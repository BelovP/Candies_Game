/****************************************************************************
** Meta object code from reading C++ file 'gametheory.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gametheory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gametheory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameTheory[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      33,   11,   11,   11, 0x0a,
      45,   11,   11,   11, 0x0a,
      65,   11,   11,   11, 0x0a,
      81,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameTheory[] = {
    "GameTheory\0\0SwitchTurnToPlayer()\0"
    "StartGame()\0HeapButtonClicked()\0"
    "CandiesChosen()\0OkButtonClicked()\0"
};

void GameTheory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameTheory *_t = static_cast<GameTheory *>(_o);
        switch (_id) {
        case 0: _t->SwitchTurnToPlayer(); break;
        case 1: _t->StartGame(); break;
        case 2: _t->HeapButtonClicked(); break;
        case 3: _t->CandiesChosen(); break;
        case 4: _t->OkButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GameTheory::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameTheory::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameTheory,
      qt_meta_data_GameTheory, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameTheory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameTheory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameTheory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameTheory))
        return static_cast<void*>(const_cast< GameTheory*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameTheory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE