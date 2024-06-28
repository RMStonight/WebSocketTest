/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *serverTab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *serverPort;
    QPushButton *openServerBtn;
    QPushButton *closeServerBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *serverState;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QPlainTextEdit *forServerMsg;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QComboBox *addressList;
    QPushButton *sendServerBtn;
    QPlainTextEdit *sendServerMsg;
    QWidget *clientTab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *wsUrl;
    QPushButton *connectServerBtn;
    QPushButton *disconnectServerBtn;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ClientState;
    QLabel *label_7;
    QPlainTextEdit *forClientMsg;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *sendClientBtn;
    QPlainTextEdit *sendClientMsg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(812, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(11);
        tabWidget->setFont(font);
        serverTab = new QWidget();
        serverTab->setObjectName(QString::fromUtf8("serverTab"));
        verticalLayout = new QVBoxLayout(serverTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(serverTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(18, 40, 104);"));

        horizontalLayout_2->addWidget(label_4);

        serverPort = new QSpinBox(serverTab);
        serverPort->setObjectName(QString::fromUtf8("serverPort"));
        serverPort->setMinimumSize(QSize(80, 30));
        serverPort->setMaximumSize(QSize(80, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        serverPort->setFont(font2);
        serverPort->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(85, 170, 255);"));
        serverPort->setMinimum(1);
        serverPort->setMaximum(100000);
        serverPort->setValue(1234);

        horizontalLayout_2->addWidget(serverPort);

        openServerBtn = new QPushButton(serverTab);
        openServerBtn->setObjectName(QString::fromUtf8("openServerBtn"));
        openServerBtn->setMinimumSize(QSize(0, 40));
        openServerBtn->setMaximumSize(QSize(16777215, 40));
        openServerBtn->setFont(font1);
        openServerBtn->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(openServerBtn);

        closeServerBtn = new QPushButton(serverTab);
        closeServerBtn->setObjectName(QString::fromUtf8("closeServerBtn"));
        closeServerBtn->setEnabled(false);
        closeServerBtn->setMinimumSize(QSize(0, 40));
        closeServerBtn->setMaximumSize(QSize(16777215, 40));
        closeServerBtn->setFont(font1);
        closeServerBtn->setCursor(QCursor(Qt::PointingHandCursor));
        closeServerBtn->setCheckable(false);
        closeServerBtn->setChecked(false);
        closeServerBtn->setFlat(false);

        horizontalLayout_2->addWidget(closeServerBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        serverState = new QLabel(serverTab);
        serverState->setObjectName(QString::fromUtf8("serverState"));
        serverState->setMinimumSize(QSize(0, 30));
        serverState->setMaximumSize(QSize(16777215, 30));
        serverState->setFont(font1);
        serverState->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        serverState->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(serverState);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(serverTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(18, 40, 104);"));

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        forServerMsg = new QPlainTextEdit(serverTab);
        forServerMsg->setObjectName(QString::fromUtf8("forServerMsg"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(12);
        forServerMsg->setFont(font3);
        forServerMsg->setReadOnly(true);

        verticalLayout->addWidget(forServerMsg);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(serverTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setMaximumSize(QSize(16777215, 30));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(18, 40, 104);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(serverTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(16777215, 30));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(18, 40, 104);"));

        horizontalLayout->addWidget(label_3);

        addressList = new QComboBox(serverTab);
        addressList->setObjectName(QString::fromUtf8("addressList"));
        addressList->setMinimumSize(QSize(350, 30));
        addressList->setMaximumSize(QSize(350, 30));
        addressList->setFont(font2);
        addressList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(85, 170, 255);"));

        horizontalLayout->addWidget(addressList);

        sendServerBtn = new QPushButton(serverTab);
        sendServerBtn->setObjectName(QString::fromUtf8("sendServerBtn"));
        sendServerBtn->setEnabled(false);
        sendServerBtn->setMinimumSize(QSize(0, 40));
        sendServerBtn->setMaximumSize(QSize(16777215, 40));
        sendServerBtn->setFont(font1);
        sendServerBtn->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(sendServerBtn);


        verticalLayout->addLayout(horizontalLayout);

        sendServerMsg = new QPlainTextEdit(serverTab);
        sendServerMsg->setObjectName(QString::fromUtf8("sendServerMsg"));
        sendServerMsg->setMinimumSize(QSize(0, 150));
        sendServerMsg->setMaximumSize(QSize(16777215, 150));
        sendServerMsg->setFont(font3);

        verticalLayout->addWidget(sendServerMsg);

        tabWidget->addTab(serverTab, QString());
        clientTab = new QWidget();
        clientTab->setObjectName(QString::fromUtf8("clientTab"));
        verticalLayout_3 = new QVBoxLayout(clientTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(clientTab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 30));
        label_6->setMaximumSize(QSize(16777215, 30));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(18, 40, 104);"));

        horizontalLayout_3->addWidget(label_6);

        wsUrl = new QLineEdit(clientTab);
        wsUrl->setObjectName(QString::fromUtf8("wsUrl"));
        wsUrl->setMinimumSize(QSize(500, 30));
        wsUrl->setMaximumSize(QSize(16777215, 30));
        wsUrl->setFont(font2);
        wsUrl->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(85, 170, 255);"));

        horizontalLayout_3->addWidget(wsUrl);

        connectServerBtn = new QPushButton(clientTab);
        connectServerBtn->setObjectName(QString::fromUtf8("connectServerBtn"));
        connectServerBtn->setMinimumSize(QSize(0, 40));
        connectServerBtn->setMaximumSize(QSize(16777215, 40));
        connectServerBtn->setFont(font1);
        connectServerBtn->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(connectServerBtn);

        disconnectServerBtn = new QPushButton(clientTab);
        disconnectServerBtn->setObjectName(QString::fromUtf8("disconnectServerBtn"));
        disconnectServerBtn->setEnabled(false);
        disconnectServerBtn->setMinimumSize(QSize(0, 40));
        disconnectServerBtn->setMaximumSize(QSize(16777215, 40));
        disconnectServerBtn->setFont(font1);
        disconnectServerBtn->setCursor(QCursor(Qt::PointingHandCursor));
        disconnectServerBtn->setCheckable(false);
        disconnectServerBtn->setChecked(false);
        disconnectServerBtn->setFlat(false);

        horizontalLayout_3->addWidget(disconnectServerBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        ClientState = new QLabel(clientTab);
        ClientState->setObjectName(QString::fromUtf8("ClientState"));
        ClientState->setMinimumSize(QSize(0, 30));
        ClientState->setMaximumSize(QSize(16777215, 30));
        ClientState->setFont(font1);
        ClientState->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        ClientState->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(ClientState);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_7 = new QLabel(clientTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(18, 40, 104);"));

        verticalLayout_3->addWidget(label_7);

        forClientMsg = new QPlainTextEdit(clientTab);
        forClientMsg->setObjectName(QString::fromUtf8("forClientMsg"));
        forClientMsg->setFont(font3);
        forClientMsg->setReadOnly(true);

        verticalLayout_3->addWidget(forClientMsg);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(clientTab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 30));
        label_8->setMaximumSize(QSize(16777215, 30));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(18, 40, 104);"));

        horizontalLayout_4->addWidget(label_8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        sendClientBtn = new QPushButton(clientTab);
        sendClientBtn->setObjectName(QString::fromUtf8("sendClientBtn"));
        sendClientBtn->setEnabled(false);
        sendClientBtn->setMinimumSize(QSize(0, 40));
        sendClientBtn->setMaximumSize(QSize(16777215, 40));
        sendClientBtn->setFont(font1);
        sendClientBtn->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(sendClientBtn);


        verticalLayout_3->addLayout(horizontalLayout_4);

        sendClientMsg = new QPlainTextEdit(clientTab);
        sendClientMsg->setObjectName(QString::fromUtf8("sendClientMsg"));
        sendClientMsg->setMinimumSize(QSize(0, 150));
        sendClientMsg->setMaximumSize(QSize(16777215, 150));
        sendClientMsg->setFont(font3);

        verticalLayout_3->addWidget(sendClientMsg);

        tabWidget->addTab(clientTab, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 812, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        closeServerBtn->setDefault(false);
        disconnectServerBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", nullptr));
        openServerBtn->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        closeServerBtn->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        serverState->setText(QCoreApplication::translate("MainWindow", "\347\246\273\347\272\277", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200:", nullptr));
        sendServerBtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        sendServerBtn->setShortcut(QCoreApplication::translate("MainWindow", "Shift+Return", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(serverTab), QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\253\257", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200\357\274\232", nullptr));
        connectServerBtn->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        disconnectServerBtn->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200", nullptr));
        ClientState->setText(QCoreApplication::translate("MainWindow", "\347\246\273\347\272\277", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\357\274\232", nullptr));
        sendClientBtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        sendClientBtn->setShortcut(QCoreApplication::translate("MainWindow", "Shift+Return", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(clientTab), QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
