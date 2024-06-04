#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("websocket测试");

    // 初始化Tab标签
    ui->tabWidget->setStyleSheet(
                "QTabWidget::pane {"
                "    border: none;"
                "}"

                "QTabBar::tab {"
                "    background-color: #F0F0F0;"
                "    color: #333333;"
                "    padding: 8px 16px;"
                "    border-top-left-radius: 4px;"
                "    border-top-right-radius: 4px;"
                "}"

                "QTabBar::tab:hover {"
                "    background-color: #E0E0E0;"
                "}"

                "QTabBar::tab:selected {"
                "    background-color: #FFFFFF;"
//                "    color: #007BFF;"
                "    font-weight: bold;"
                "}"

                "QTabWidget::tab-bar {"
                "    alignment: left;"
                "}"
                );

    // 设置客户端IP格式
    // 创建一个正则表达式验证器，确保输入的格式是 IP 地址的正确格式
    QRegExpValidator *ipValidator = new QRegExpValidator(QRegExp("^((25[0-5]|2[0-4]\\d|[01]?\\d\\d?)\\.){3}(25[0-5]|2[0-4]\\d|[01]?\\d\\d?)$"), this);
    ui->socketIP->setValidator(ipValidator);
    ui->socketIP->setPlaceholderText("输入IP地址");  // 设置占位符文本

    // 设置QPlainText行数上限
    ui->forServerMsg->setMaximumBlockCount(msgMaxBlocks);
    ui->forClientMsg->setMaximumBlockCount(msgMaxBlocks);
}

MainWindow::~MainWindow()
{
    m_server->stopServer();
    delete m_server;  // 删除 m_server 对象
    delete m_socket;  // 删除 m_socket 对象
    delete ui;
}

// =======================================================================================
// ========================================通用函数========================================
// =======================================================================================
// 返回系统时间yyyy-MM-dd hh:mm:ss
QString MainWindow::getSysTime()
{
    // 系统时间获取方式，备用
    QDateTime cur_time = QDateTime::currentDateTime();
    QString timeStr = cur_time.toString("yyyy-MM-dd hh:mm:ss");
//    qDebug() << timeStr;
    return timeStr;
}

// 警告信息
void MainWindow::alertMsg(const QString& msg)
{
    // 创建一个信息框
    QMessageBox msgBox;
    msgBox.setWindowTitle(QStringLiteral("提示"));
    msgBox.setText(msg);
    msgBox.exec();  // 显示弹窗并等待用户关闭
}

// 消息区域新增内容指定颜色
void MainWindow::appendColoredText(QPlainTextEdit *edit, const QString& type, const QString &text, const QString &msgHeader) {
    // 此处获取currentValue和maximumValue是确认新消息接收前滚动条处于什么位置
    QScrollBar *vScrollBar = edit->verticalScrollBar();
    int currentValue = vScrollBar->value();
    int maximumValue = vScrollBar->maximum();

    QTextCursor cursor(edit->document());
    cursor.movePosition(QTextCursor::End);
    QTextCharFormat format;
    if (type == QStringLiteral("send")) {
        format.setForeground(QColor(QStringLiteral("#008000")));
        cursor.setCharFormat(format);
        QString info = QStringLiteral("发给 ") + msgHeader + QStringLiteral(" 的消息 ") + getSysTime() + QStringLiteral("\n");
        cursor.insertText(info);

        format.setForeground(QColor(QStringLiteral("#000000")));
        cursor.setCharFormat(format);
        cursor.insertText(text + QStringLiteral("\n"));
    } else if (type == QStringLiteral("get")) {
        format.setForeground(QColor(QStringLiteral("#0000ff")));
        cursor.setCharFormat(format);
        QString info = QStringLiteral("收到 ") + msgHeader + QStringLiteral(" 的消息 ") + getSysTime() + QStringLiteral("\n");
        cursor.insertText(info);

        format.setForeground(QColor(QStringLiteral("#000000")));
        cursor.setCharFormat(format);
        cursor.insertText(text + QStringLiteral("\n"));
    } else if (type == QStringLiteral("alert")) {
        format.setForeground(QColor(QStringLiteral("#ff0000")));
        cursor.setCharFormat(format);
        cursor.insertText(text + QStringLiteral("\n"));
    }

//    qDebug() << "currentValue: " << currentValue << ", maximumValue:" << maximumValue;

    // 判断当前滚动条是否在最底部
    if (currentValue == maximumValue) {
        vScrollBar->setValue(vScrollBar->maximum());
    }

    // 判断是否达到最大值，达到则删除前最大值的1/3的行数
    if(edit->document()->blockCount() >= msgMaxBlocks) {
        QTextCursor cursor(edit->document());

        // 开始一个编辑块
        cursor.beginEditBlock();

        // 移动光标到文档开始
        cursor.movePosition(QTextCursor::Start);

        // 循环删除前n行
        for (int i = 0; i < msgMaxBlocks / 3; ++i) {
            cursor.movePosition(QTextCursor::StartOfBlock);
            cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
            cursor.removeSelectedText();
            if (cursor.atBlockEnd()) {
                cursor.deleteChar();
            }
        }
        // 结束编辑块
        cursor.endEditBlock();
        // 刷新到底部
        vScrollBar->setValue(vScrollBar->maximum());
    }
}
// =======================================================================================

// =======================================================================================
// ===================================websocket服务端相关===================================
// =======================================================================================
// 按钮开启websocket服务端
void MainWindow::on_openServerBtn_clicked()
{
    // 初始化webSocketServer对象
    m_server = new WebSocketServer;
    // 服务端启动成功
    if(m_server->startServer(ui->serverPort->text().toUInt())){
        connect(m_server, &WebSocketServer::needUpdateList, this, &MainWindow::updateIPListAndPortList);
        connect(m_server, &WebSocketServer::getClientMsg, this, &MainWindow::handleClientMsg);
        connect(m_server, &WebSocketServer::promptInfo, this, &MainWindow::handlePromptInfo);
        updateVisualState(QStringLiteral("online"));
    }
}

// 按钮关闭websocket服务端
void MainWindow::on_closeServerBtn_clicked()
{
    m_server->stopServer();
//    delete m_server;
    updateVisualState(QStringLiteral("offline"));
}

// 更新 addressList
void MainWindow::updateIPListAndPortList(const QMap<QPair<QString, int>, QWebSocket*>& clients)
{
    // 清空 addressList
    ui->addressList->clear();

    // 重新添加 IP 和端口号到 addressList 中
    for (const auto &client : qAsConst(clients)) {
        QString ipAddress = client->peerAddress().toString();
        int port = client->peerPort();
        QString ipAndPort = ipAddress + QStringLiteral(":") + QString::number(port);
        ui->addressList->addItem(ipAndPort);
    }
}

// 更新按钮是否可用和是否在线
void MainWindow::updateVisualState(const QString& signal)
{
    if (signal == QStringLiteral("online")) {
        // 设置按钮是否可选
        ui->openServerBtn->setEnabled(false);
        ui->closeServerBtn->setEnabled(true);
        ui->sendServerBtn->setEnabled(true);
        ui->serverPort->setEnabled(false);
        // 在线状态
        ui->serverState->setText(QStringLiteral("在线"));
        ui->serverState->setStyleSheet(QStringLiteral("color: #00ff00"));
    } else if (signal == QStringLiteral("offline")) {
        // 重置按钮是否可选
        ui->openServerBtn->setEnabled(true);
        ui->closeServerBtn->setEnabled(false);
        ui->sendServerBtn->setEnabled(false);
        ui->serverPort->setEnabled(true);
        // 在线状态
        ui->serverState->setText(QStringLiteral("离线"));
        ui->serverState->setStyleSheet(QStringLiteral("color: #ff0000"));
    }
}

// 处理接收到的数据
void MainWindow::handleClientMsg(const QString &msgHeader, const QString &message)
{
    appendColoredText(ui->forServerMsg, QStringLiteral("get"), message, msgHeader);
}

// 需要显示在msg区域的消息
void MainWindow::handlePromptInfo(const QString& msg)
{
    appendColoredText(ui->forServerMsg, QStringLiteral("alert"), msg, nullptr);
}

// 服务端向客户端发送
void MainWindow::on_sendServerBtn_clicked()
{
    // 获取ip和port
    QStringList strList = ui->addressList->currentText().split(":");
    // 判断是否分割出2个成员
    if (strList.size() >= 2) {
        QString ipAddress = strList.at(0);
        int port = strList.at(1).toUInt();
        // 发送前判断指定客户端是否还在
        // 构建键值对
        QPair<QString, int> clientKey = qMakePair(ipAddress, port);
        if (m_server->clients.contains(clientKey)) {
            m_server->sendMessageToIPAndPort(ipAddress, port, ui->sendServerMsg->toPlainText());
            appendColoredText(ui->forServerMsg, QStringLiteral("send"), ui->sendServerMsg->toPlainText(), ui->addressList->currentText());
            ui->sendServerMsg->clear();
            ui->sendServerMsg->setFocus();
        } else {
            alertMsg(QStringLiteral("指定客户端已离线"));
        }
    } else {
        alertMsg(QStringLiteral("无效的地址格式"));
    }
}
// =======================================================================================

// =======================================================================================
// ===================================websocket客户端相关===================================
// =======================================================================================
// 连接至websocket服务端
void MainWindow::on_connectServerBtn_clicked()
{
    // 点击连接按钮后
    ui->connectServerBtn->setText("连接中...");
    ui->connectServerBtn->setEnabled(false);
    // 初始化客户端
    m_socket = new WebSocketClient;
    QString m_socketServerUrl = QStringLiteral("ws://") + ui->socketIP->text() + QStringLiteral(":") + ui->socketPort->text();
    // 尝试连接至服务端
    connect(m_socket, &WebSocketClient::connectedFlag, this, &MainWindow::handleConnectResult);
    m_socket->connectServer(QUrl(m_socketServerUrl));
}

// 处理返回的连接结果
void MainWindow::handleConnectResult(bool flag)
{
    // 按钮字样切换回来
    ui->connectServerBtn->setText("连接");
    if(flag) {
        // 连接成功
        connect(m_socket, &WebSocketClient::disconnectSig, this, &MainWindow::handleDisconnectSig);
        connect(m_socket, &WebSocketClient::getServerMsg, this, &MainWindow::handleServerMsg);
        updateVisualStateClient(QStringLiteral("online"));
        const QString message = QStringLiteral("[") + getSysTime() + QStringLiteral("] 成功连接至服务端");
        appendColoredText(ui->forClientMsg, QStringLiteral("alert"), message, nullptr);
    } else {
        // 连接失败
        alertMsg("无法连接至服务端！");
        ui->connectServerBtn->setEnabled(true);
    }
}

// 断开与websocket服务端的连接
void MainWindow::on_disconnectServerBtn_clicked()
{
    handleDisconnectSig();
    m_socket->disconnectServer();
}

// 处理与服务器断开连接
void MainWindow::handleDisconnectSig()
{
    disconnect(m_socket, &WebSocketClient::disconnectSig, this, &MainWindow::handleDisconnectSig);
    disconnect(m_socket, &WebSocketClient::getServerMsg, this, &MainWindow::handleServerMsg);
    updateVisualStateClient(QStringLiteral("offline"));
    const QString message = QStringLiteral("[") + getSysTime() + QStringLiteral("] 与服务端断开连接");
    appendColoredText(ui->forClientMsg, QStringLiteral("alert"), message, nullptr);
}

// 更新按钮是否可用和是否在线
void MainWindow::updateVisualStateClient(const QString& signal)
{
    if (signal == QStringLiteral("online")) {
        // 设置按钮是否可选
        ui->connectServerBtn->setEnabled(false);
        ui->disconnectServerBtn->setEnabled(true);
        ui->sendClientBtn->setEnabled(true);
        // 在线状态
        ui->ClientState->setText(QStringLiteral("在线"));
        ui->ClientState->setStyleSheet(QStringLiteral("color: #00ff00"));
    } else if (signal == QStringLiteral("offline")) {
        // 设置按钮是否可选
        ui->connectServerBtn->setEnabled(true);
        ui->disconnectServerBtn->setEnabled(false);
        ui->sendClientBtn->setEnabled(false);
        // 在线状态
        ui->ClientState->setText(QStringLiteral("离线"));
        ui->ClientState->setStyleSheet(QStringLiteral("color: #ff0000"));
    }
}

// 处理接收到服务端的数据
void MainWindow::handleServerMsg(const QString &message)
{
    const QString msgHeader = ui->socketIP->text() + QStringLiteral(":") + ui->socketPort->text();
    appendColoredText(ui->forClientMsg, QStringLiteral("get"), message, msgHeader);
}

// 客户端向服务端发送
void MainWindow::on_sendClientBtn_clicked()
{
    m_socket->sendMessage(ui->sendClientMsg->toPlainText());
    appendColoredText(ui->forClientMsg, QStringLiteral("send"), ui->sendClientMsg->toPlainText(), ui->socketIP->text() + QStringLiteral(":") + ui->socketPort->text());
    ui->sendClientMsg->clear();
    ui->sendClientMsg->setFocus();
}

// 当刷新 QPlainTextEdit 内容时，如果不位于该标签页，那么在页面内容超出一整页时，会发生多余的一整页空白行问题
// 如下操作相当于切换到某个页面时，强制刷新，添加一行回车再删除一行
void MainWindow::on_tabWidget_currentChanged(int index)
{
    const int serverIndex = ui->tabWidget->indexOf(ui->serverTab);
    const int clientIndex = ui->tabWidget->indexOf(ui->clientTab);
    if(index == serverIndex) {
        // 如果切换至服务端tab
        appendColoredText(ui->forServerMsg, QStringLiteral("alert"), nullptr, nullptr);
        QTextCursor cursor(ui->forServerMsg->document());
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::PreviousBlock, QTextCursor::KeepAnchor);
        cursor.removeSelectedText();
    }else if (index == clientIndex) {
        // 如果切换至客户端tab
        appendColoredText(ui->forClientMsg, QStringLiteral("alert"), nullptr, nullptr);
        QTextCursor cursor(ui->forClientMsg->document());
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::PreviousBlock, QTextCursor::KeepAnchor);
        cursor.removeSelectedText();
    }
}
