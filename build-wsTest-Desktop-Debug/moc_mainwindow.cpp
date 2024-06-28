/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../wsTest/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[419];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_openServerBtn_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "on_closeServerBtn_clicked"
QT_MOC_LITERAL(4, 63, 23), // "updateIPListAndPortList"
QT_MOC_LITERAL(5, 87, 36), // "QMap<QPair<QString,int>,QWebS..."
QT_MOC_LITERAL(6, 124, 7), // "clients"
QT_MOC_LITERAL(7, 132, 15), // "handleClientMsg"
QT_MOC_LITERAL(8, 148, 9), // "msgHeader"
QT_MOC_LITERAL(9, 158, 7), // "message"
QT_MOC_LITERAL(10, 166, 16), // "handlePromptInfo"
QT_MOC_LITERAL(11, 183, 3), // "msg"
QT_MOC_LITERAL(12, 187, 24), // "on_sendServerBtn_clicked"
QT_MOC_LITERAL(13, 212, 27), // "on_connectServerBtn_clicked"
QT_MOC_LITERAL(14, 240, 30), // "on_disconnectServerBtn_clicked"
QT_MOC_LITERAL(15, 271, 19), // "handleConnectResult"
QT_MOC_LITERAL(16, 291, 4), // "flag"
QT_MOC_LITERAL(17, 296, 6), // "errMsg"
QT_MOC_LITERAL(18, 303, 19), // "handleDisconnectSig"
QT_MOC_LITERAL(19, 323, 15), // "handleServerMsg"
QT_MOC_LITERAL(20, 339, 24), // "on_sendClientBtn_clicked"
QT_MOC_LITERAL(21, 364, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(22, 392, 5), // "index"
QT_MOC_LITERAL(23, 398, 20) // "handleConnectTimeout"

    },
    "MainWindow\0on_openServerBtn_clicked\0"
    "\0on_closeServerBtn_clicked\0"
    "updateIPListAndPortList\0"
    "QMap<QPair<QString,int>,QWebSocket*>\0"
    "clients\0handleClientMsg\0msgHeader\0"
    "message\0handlePromptInfo\0msg\0"
    "on_sendServerBtn_clicked\0"
    "on_connectServerBtn_clicked\0"
    "on_disconnectServerBtn_clicked\0"
    "handleConnectResult\0flag\0errMsg\0"
    "handleDisconnectSig\0handleServerMsg\0"
    "on_sendClientBtn_clicked\0"
    "on_tabWidget_currentChanged\0index\0"
    "handleConnectTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       7,    2,   89,    2, 0x08 /* Private */,
      10,    1,   94,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    2,  100,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,
      19,    1,  106,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,
      21,    1,  110,    2, 0x08 /* Private */,
      23,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_openServerBtn_clicked(); break;
        case 1: _t->on_closeServerBtn_clicked(); break;
        case 2: _t->updateIPListAndPortList((*reinterpret_cast< const QMap<QPair<QString,int>,QWebSocket*>(*)>(_a[1]))); break;
        case 3: _t->handleClientMsg((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->handlePromptInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_sendServerBtn_clicked(); break;
        case 6: _t->on_connectServerBtn_clicked(); break;
        case 7: _t->on_disconnectServerBtn_clicked(); break;
        case 8: _t->handleConnectResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->handleDisconnectSig(); break;
        case 10: _t->handleServerMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_sendClientBtn_clicked(); break;
        case 12: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->handleConnectTimeout(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
