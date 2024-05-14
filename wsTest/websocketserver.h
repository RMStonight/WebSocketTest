#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include <QObject>
#include <QWebSocketServer>
#include <QMap>
#include <QPair>
#include <QWebSocket>
#include <QComboBox>

class WebSocketServer: public QObject
{
    Q_OBJECT
public:
    explicit WebSocketServer(QObject *parent = nullptr);
    ~WebSocketServer();

    // 开启服务端
    bool startServer(quint16 port);
    // 关闭服务端
    void stopServer();
    // 声明一个 QMap 以存储客户端连接的 IP 地址和端口号与对应的 WebSocket 对象
    QMap<QPair<QString, int>, QWebSocket*> clients;

signals:
    // 需要更新列表的信号
    void needUpdateList(const QMap<QPair<QString, int>, QWebSocket*>& clients);
    // 接收到的客户端消息
    void getClientMsg(const QString &msgHeader, const QString &message);
    // 需要显示在msg区域的消息
    void promptInfo(const QString& msg);

public slots:
    // 新的客户端连接
    void onNewConnection();
    // 客户端断开连接
    void socketDisconnected();
    // 处理客户端消息
    void processTextMessage(const QString &message);
    // 向指定 IP 地址和端口号发送消息
    void sendMessageToIPAndPort(const QString& ipAddress, int port, const QString& msg);

private:
    QWebSocketServer *webSocketServer;
    // 返回系统时间戳
    QString getSysTime();
    // 警告弹窗
    void alertMsg(const QString &msg);
};

#endif // WEBSOCKETSERVER_H
