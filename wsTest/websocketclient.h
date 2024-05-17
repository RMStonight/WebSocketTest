#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QMap>
#include <QPair>
#include <QWebSocket>
#include <QComboBox>
#include <QTimer>


class WebSocketClient: public QObject
{
    Q_OBJECT
public:
    explicit WebSocketClient(QObject *parent = nullptr);
    ~WebSocketClient();

    // 主动连接服务端
    void connectServer(QUrl url);
    // 主动断开连接时的操作
    void disconnectServer();

signals:
    // 连接标志位信号，ture为连接成功
    void connectedFlag(bool flag);
    // 断开连接的信号
    void disconnectSig();
    // 接收到的服务端消息
    void getServerMsg(const QString &message);

public slots:
    // 成功连接至服务端
    void webSocketConnected();
    // 响应与服务端断开连接
    void webSocketDisconnected();
    // 处理接收到的服务端消息
    void handleSocketMsg(const QString &message);
    // 向指定 IP 地址和端口号发送消息
    void sendMessage(const QString& msg);
    // 处理连接失败
    void onError(QAbstractSocket::SocketError error);
    // 处理连接超时
    void handleTimeout();

private:
    QWebSocket *webSocket;
    // 返回系统时间戳
    QString getSysTime();
    // 警告弹窗
    void alertMsg(const QString &msg);
    // 判断连接超时的定时器
    QTimer *timeoutTimer;
};

#endif // WEBSOCKETCLIENT_H
