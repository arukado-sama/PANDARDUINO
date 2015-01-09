/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Mar 19 09:51:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      43,   38,   11,   11, 0x08,
      88,   38,   11,   11, 0x08,
     134,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     202,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     224,   38,   11,   11, 0x08,
     269,   11,   11,   11, 0x08,
     296,   11,   11,   11, 0x08,
     321,   11,   11,   11, 0x08,
     352,  346,   11,   11, 0x08,
     393,   38,   11,   11, 0x08,
     429,  346,   11,   11, 0x08,
     464,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_buttonUpload_clicked()\0"
    "arg1\0on_cardComboBox_currentIndexChanged(QString)\0"
    "on_speedComboBox_currentIndexChanged(QString)\0"
    "on_lineEdit_returnPressed()\0"
    "on_buttonClear_clicked()\0affichUpload()\0"
    "sendData()\0readData()\0"
    "on_portComboBox_currentIndexChanged(QString)\0"
    "on_buttonConnect_clicked()\0"
    "on_buttonBuild_clicked()\0"
    "on_buttonAbout_clicked()\0index\0"
    "on_textComboBox_currentIndexChanged(int)\0"
    "on_optionsLine_textChanged(QString)\0"
    "on_lineDialog_clicked(QModelIndex)\0"
    "processPendingDatagrams()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_buttonUpload_clicked(); break;
        case 1: _t->on_cardComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_speedComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_returnPressed(); break;
        case 4: _t->on_buttonClear_clicked(); break;
        case 5: _t->affichUpload(); break;
        case 6: _t->sendData(); break;
        case 7: _t->readData(); break;
        case 8: _t->on_portComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_buttonConnect_clicked(); break;
        case 10: _t->on_buttonBuild_clicked(); break;
        case 11: _t->on_buttonAbout_clicked(); break;
        case 12: _t->on_textComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_optionsLine_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_lineDialog_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->processPendingDatagrams(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
