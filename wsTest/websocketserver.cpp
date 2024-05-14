#include "websocketserver.h"
#include <QMessageBox>
#include <QDebug>

WebSocketServer::WebSocketServer(QObject *parent)
    : QObject(parent)
    , webSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"), QWebSocketServer::NonSecureMode, this))
{

}

WebSocketServer::~WebSocketServer()
{
    stopServer();
    delete webSocketServer;  // 删除webSocketServer 对象
}

// 返回系统时间戳
QString WebSocketServer::getSysTime()
{
    QDateTime cur_time = QDateTime::currentDateTime();
    QString timeStr = cur_time.toString("yyyy-MM-dd hh:mm:ss");
    return QStringLiteral("[") + timeStr + QStringLiteral("] ");
}

// 警告弹窗
void WebSocketServer::alertMsg(const QString &msg)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(QStringLiteral("提示"));
    msgBox.setText(msg);
    msgBox.exec();
}

// 开启服务端
bool WebSocketServer::startServer(quint16 port)
{
    if (webSocketServer->listen(QHostAddress::AnyIPv4, port)) {
        connect(webSocketServer, &QWebSocketServer::newConnection, this, &WebSocketServer::onNewConnection);
        qDebug() << (QStringLiteral("Server started on port: ") + QString::number(webSocketServer->serverPort()));
        return true;
    } else {
        qDebug() << (QStringLiteral("Server could not start!"));
        alertMsg(QStringLiteral("无法打开指定端口!"));
        return false;
    }
}

// 关闭服务端
void WebSocketServer::stopServer()
{
    if (webSocketServer->isListening()) {
        webSocketServer->close();
        // 先断开与客户端的连接
        for (auto client : clients) {
            disconnect(client, &QWebSocket::disconnected, this, &WebSocketServer::socketDisconnected);
            client->close();
        }
        // 删除clients
        qDeleteAll(clients.begin(), clients.end());
        qDebug() << (QStringLiteral("Server closed"));
    } else {
        qDebug() << (QStringLiteral("Server is not running"));
    }
}

// 新的客户端连接
void WebSocketServer::onNewConnection()
{
    QWebSocket *socket = webSocketServer->nextPendingConnection();
    connect(socket, &QWebSocket::textMessageReceived, this, &WebSocketServer::processTextMessage);
    connect(socket, &QWebSocket::disconnected, this, &WebSocketServer::socketDisconnected);

    // 记录客户端的IP地址和端口号
    QString ipAddress = socket->peerAddress().toString();
    int port = socket->peerPort();
    clients[qMakePair(ipAddress, port)] = socket;
    emit promptInfo(getSysTime() + QStringLiteral("新的客户端连入:") + socket->peerAddress().toString() + QStringLiteral(":") + QString::number(socket->peerPort()));
    // 需要发送一个连接信号
    emit needUpdateList(clients);
}

// 客户端断开连接
void WebSocketServer::socketDisconnected()
{
    QWebSocket *client = qobject_cast<QWebSocket *>(sender());
    if (client) {
        QMap<QPair<QString, int>, QWebSocket*>::const_iterator it = clients.constBegin();
        while (it != clients.constEnd()) {
            if (it.value() == client) {
                QString ipAddress = it.key().first;
                int port = it.key().second;
                emit promptInfo(getSysTime() + QStringLiteral("客户端断开:") + ipAddress + QStringLiteral(":") + QString::number(port));
                clients.remove(it.key());
                break;
            }
            ++it;
        }
        client->deleteLater();
    }
    // 需要发送一个断连信号
    emit needUpdateList(clients);
}

// 处理客户端消息
void WebSocketServer::processTextMessage(const QString &message)
{
    QWebSocket *client = qobject_cast<QWebSocket *>(sender());
    if (client) {
        const QString msgHeader = client->peerAddress().toString() + QStringLiteral(":") + QString::number(client->peerPort());
        emit getClientMsg(msgHeader, message);
    }
}

// 向指定 IP 地址和端口号发送消息
void WebSocketServer::sendMessageToIPAndPort(const QString& ipAddress, int port, const QString& msg)
{
    QPair<QString, int> key = qMakePair(ipAddress, port);
    if (clients.contains(key)) {
        QWebSocket *client = clients[key];
        if (client->isValid()) {
            client->sendTextMessage(msg);
        }
    }
}
