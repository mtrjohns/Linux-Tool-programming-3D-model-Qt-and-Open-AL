/****************************************************************************
** Meta object code from reading C++ file 'OpenALWithQT.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OpenALwithQT/OpenALWithQT.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenALWithQT.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OpenALwithQT[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      44,   13,   13,   13, 0x08,
      75,   13,   13,   13, 0x08,
     105,   13,   13,   13, 0x08,
     135,   13,   13,   13, 0x08,
     166,   13,   13,   13, 0x08,
     196,   13,   13,   13, 0x08,
     226,   13,   13,   13, 0x08,
     257,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OpenALwithQT[] = {
    "OpenALwithQT\0\0on_PlayBattleButton_clicked()\0"
    "on_PauseBattleButton_clicked()\0"
    "on_StopBattleButton_clicked()\0"
    "on_PlayGunOneButton_clicked()\0"
    "on_PauseGunOneButton_clicked()\0"
    "on_StopGunOneButton_clicked()\0"
    "on_PlayGunTwoButton_clicked()\0"
    "on_PauseGunTwoButton_clicked()\0"
    "on_StopGunTwoButton_clicked()\0"
};

void OpenALwithQT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OpenALwithQT *_t = static_cast<OpenALwithQT *>(_o);
        switch (_id) {
        case 0: _t->on_PlayBattleButton_clicked(); break;
        case 1: _t->on_PauseBattleButton_clicked(); break;
        case 2: _t->on_StopBattleButton_clicked(); break;
        case 3: _t->on_PlayGunOneButton_clicked(); break;
        case 4: _t->on_PauseGunOneButton_clicked(); break;
        case 5: _t->on_StopGunOneButton_clicked(); break;
        case 6: _t->on_PlayGunTwoButton_clicked(); break;
        case 7: _t->on_PauseGunTwoButton_clicked(); break;
        case 8: _t->on_StopGunTwoButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OpenALwithQT::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OpenALwithQT::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OpenALwithQT,
      qt_meta_data_OpenALwithQT, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenALwithQT::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenALwithQT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenALwithQT::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenALwithQT))
        return static_cast<void*>(const_cast< OpenALwithQT*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OpenALwithQT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
