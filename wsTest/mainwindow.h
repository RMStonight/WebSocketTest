#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QWebSocketServer>
#include <QWebSocket>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <websocketserver.h>
#include <websocketclient.h>
#include <QScrollBar>
#include <QPlainTextEdit>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextBlock>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // ===================================websocket服务端相关===================================
    // 开启websocket服务端
    void on_openServerBtn_clicked();
    // 关闭websocket服务端
    void on_closeServerBtn_clicked();
    // 更新 ipList 和 portList
    void updateIPListAndPortList(const QMap<QPair<QString, int>, QWebSocket*>& clients);
    // 处理接收到的数据
    void handleClientMsg(const QString &msgHeader, const QString &message);
    // 需要显示在msg区域的消息
    void handlePromptInfo(const QString& msg);
    // 服务端向客户端发送
    void on_sendServerBtn_clicked();


    // ===================================websocket客户端相关===================================
    // 连接至websocket服务端
    void on_connectServerBtn_clicked();
    // 断开与websocket服务端的连接
    void on_disconnectServerBtn_clicked();
    // 处理返回的连接结果
    void handleConnectResult(bool flag, QString errMsg);
    // 处理与服务器断开连接
    void handleDisconnectSig();
    // 处理接收到服务端的数据
    void handleServerMsg(const QString &message);
    // 客户端向服务端发送
    void on_sendClientBtn_clicked();

    void on_tabWidget_currentChanged(int index);
    // 处理连接超时
    void handleConnectTimeout();

private:
    Ui::MainWindow *ui;
    // 返回系统时间
    QString getSysTime();
    // 警告信息
    void alertMsg(const QString& msg);
    // websocket服务端
    WebSocketServer* m_server;
    // websocket客户端
    WebSocketClient* m_socket;
    // 更新按钮是否可用和是否在线
    void updateVisualState(const QString& signal);
    void updateVisualStateClient(const QString& signal);
    // 消息区域新增内容指定颜色
    void appendColoredText(QPlainTextEdit *edit, const QString& type, const QString &text, const QString &msgHeader);
    // 接收消息的文本框的最大blocks数量
    const int msgMaxBlocks = 3000;
    // 客户端连接成功时，记录下ws内容
    QString wsName;
    // 客户端尝试连接时的定时器
    QTimer *connectTimer;
};
#endif // MAINWINDOW_H
