/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../samp4_8/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[42];
    char stringdata0[408];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 25), // "on_actAddFolder_triggered"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 24), // "on_actAddFiles_triggered"
QT_MOC_LITERAL(63, 32), // "on_treeWidget_currentItemChanged"
QT_MOC_LITERAL(96, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(113, 7), // "current"
QT_MOC_LITERAL(121, 8), // "previous"
QT_MOC_LITERAL(130, 26), // "on_actDeleteItem_triggered"
QT_MOC_LITERAL(157, 25), // "on_actScanItems_triggered"
QT_MOC_LITERAL(183, 24), // "on_actZoomFitH_triggered"
QT_MOC_LITERAL(208, 22), // "on_actZoomIn_triggered"
QT_MOC_LITERAL(231, 28), // "on_actZoomRealSize_triggered"
QT_MOC_LITERAL(260, 25), // "on_actDockVisible_toggled"
QT_MOC_LITERAL(286, 4), // "arg1"
QT_MOC_LITERAL(291, 25), // "on_actDockFloat_triggered"
QT_MOC_LITERAL(317, 7), // "checked"
QT_MOC_LITERAL(325, 33), // "on_dockWidget_2_visibilityCha..."
QT_MOC_LITERAL(359, 7), // "visible"
QT_MOC_LITERAL(367, 31), // "on_dockWidget_2_topLevelChanged"
QT_MOC_LITERAL(399, 8) // "topLevel"

    },
    "MainWindow\0on_actAddFolder_triggered\0"
    "\0on_actAddFiles_triggered\0"
    "on_treeWidget_currentItemChanged\0"
    "QTreeWidgetItem*\0current\0previous\0"
    "on_actDeleteItem_triggered\0"
    "on_actScanItems_triggered\0"
    "on_actZoomFitH_triggered\0"
    "on_actZoomIn_triggered\0"
    "on_actZoomRealSize_triggered\0"
    "on_actDockVisible_toggled\0arg1\0"
    "on_actDockFloat_triggered\0checked\0"
    "on_dockWidget_2_visibilityChanged\0"
    "visible\0on_dockWidget_2_topLevelChanged\0"
    "topLevel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    2,   88,    2, 0x08,    3 /* Private */,
       8,    0,   93,    2, 0x08,    6 /* Private */,
       9,    0,   94,    2, 0x08,    7 /* Private */,
      10,    0,   95,    2, 0x08,    8 /* Private */,
      11,    0,   96,    2, 0x08,    9 /* Private */,
      12,    0,   97,    2, 0x08,   10 /* Private */,
      13,    1,   98,    2, 0x08,   11 /* Private */,
      15,    1,  101,    2, 0x08,   13 /* Private */,
      17,    1,  104,    2, 0x08,   15 /* Private */,
      19,    1,  107,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actAddFolder_triggered(); break;
        case 1: _t->on_actAddFiles_triggered(); break;
        case 2: _t->on_treeWidget_currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 3: _t->on_actDeleteItem_triggered(); break;
        case 4: _t->on_actScanItems_triggered(); break;
        case 5: _t->on_actZoomFitH_triggered(); break;
        case 6: _t->on_actZoomIn_triggered(); break;
        case 7: _t->on_actZoomRealSize_triggered(); break;
        case 8: _t->on_actDockVisible_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_actDockFloat_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_dockWidget_2_visibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_dockWidget_2_topLevelChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
