#include "websocketclient.h"
#include <QMessageBox>
#include <QDebug>

WebSocketClient::WebSocketClient(QObject *parent)
    : QObject(parent)
    , webSocket(new QWebSocket)
{
}

WebSocketClient::~WebSocketClient()
{
    webSocket->deleteLater();
}

// 返回系统时间戳
QString WebSocketClient::getSysTime()
{
    QDateTime cur_time = QDateTime::currentDateTime();
    QString timeStr = cur_time.toString("yyyy-MM-dd hh:mm:ss");
    return QStringLiteral("[") + timeStr + QStringLiteral("] ");
}

// 警告弹窗
void WebSocketClient::alertMsg(const QString &msg)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(QStringLiteral("提示"));
    msgBox.setText(msg);
    msgBox.exec();
}

// 主动连接服务端
void WebSocketClient::connectServer(QUrl url)
{
    // 设置定时器防止过长时间的连接
    timeoutTimer = new QTimer;
    // 连接超时信号和槽
    connect(timeoutTimer, &QTimer::timeout, this, &WebSocketClient::handleTimeout);

    // 监测连接成功的信号
    connect(webSocket, &QWebSocket::connected, this, &WebSocketClient::webSocketConnected);
    connect(webSocket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, &WebSocketClient::onError);
    connect(webSocket, &QWebSocket::disconnected, this, &WebSocketClient::webSocketDisconnected);

    webSocket->open(url);

    // 启动定时器
    timeoutTimer->start(3000);
}

// 处理连接超时
void WebSocketClient::handleTimeout()
{
//    qDebug() << "webSocket.state: " << QAbstractSocket::ConnectedState;
    if (webSocket->state() != QAbstractSocket::ConnectedState) {
        // 如果连接未建立，关闭WebSocket
        webSocket->close();
        // 发送连接失败的信号
//        emit connectedFlag(false);
    }
    disconnect(timeoutTimer, &QTimer::timeout, this, &WebSocketClient::handleTimeout);
}

// 主动断开连接时的操作
void WebSocketClient::disconnectServer()
{
    disconnect(webSocket, &QWebSocket::textMessageReceived, this, &WebSocketClient::handleSocketMsg);
    webSocket->close();
}

// 处理连接失败
void WebSocketClient::onError(QAbstractSocket::SocketError error)
{
    // 取消监测连接成功的信号
    disconnect(webSocket, &QWebSocket::connected, this, &WebSocketClient::webSocketConnected);
    disconnect(webSocket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, &WebSocketClient::onError);
    QString errorMsg;

    switch (error) {
    case QAbstractSocket::ConnectionRefusedError:
        errorMsg = "Connection refused by the server.";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        errorMsg = "The remote host closed the connection.";
        break;
    case QAbstractSocket::HostNotFoundError:
        errorMsg = "The host was not found. Please check the host name and port settings.";
        break;
    case QAbstractSocket::SocketAccessError:
        errorMsg = "The socket operation failed due to lack of access permissions.";
        break;
    case QAbstractSocket::SocketTimeoutError:
        errorMsg = "The socket operation timed out.";
        break;
    case QAbstractSocket::NetworkError:
        errorMsg = "An error occurred with the network (e.g., cable unplugged).";
        break;
    default:
        errorMsg = "Unknown error occurred.";
    }
    qDebug() << "error msg: " << errorMsg;
    qDebug() << error;

    // 发送连接失败的信号
    emit connectedFlag(false,errorMsg);
}

// 成功连接至服务端
void WebSocketClient::webSocketConnected()
{
    // 取消监测连接成功的信号
    disconnect(webSocket, &QWebSocket::connected, this, &WebSocketClient::webSocketConnected);
    disconnect(webSocket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, &WebSocketClient::onError);
    // 监测收到的消息
    connect(webSocket, &QWebSocket::textMessageReceived, this, &WebSocketClient::handleSocketMsg);
    // 发送连接成功的信号
    emit connectedFlag(true, "");
}

// 响应与服务端断开连接
void WebSocketClient::webSocketDisconnected()
{
    disconnect(webSocket, &QWebSocket::disconnected, this, &WebSocketClient::webSocketDisconnected);
    disconnect(webSocket, &QWebSocket::textMessageReceived, this, &WebSocketClient::handleSocketMsg);
    emit disconnectSig();
}

// 处理接收到的服务端消息
void WebSocketClient::handleSocketMsg(const QString &message)
{
    emit getServerMsg(message);
}

// 向指定 IP 地址和端口号发送消息
void WebSocketClient::sendMessage(const QString& msg)
{
    webSocket->sendTextMessage(msg);
}
