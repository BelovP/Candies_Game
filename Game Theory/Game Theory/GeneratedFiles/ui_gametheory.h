/********************************************************************************
** Form generated from reading UI file 'gametheory.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMETHEORY_H
#define UI_GAMETHEORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameTheoryClass
{
public:
    QLCDNumber *heap_1;
    QLabel *informer;
    QLCDNumber *heap_2;
    QLCDNumber *heap_3;
    QPushButton *heap_button_1;
    QPushButton *heap_button_2;
    QPushButton *heap_button_3;
    QLineEdit *number_1;
    QLineEdit *number_2;
    QLineEdit *number_3;
    QPushButton *ok_button_1;
    QPushButton *ok_button_2;
    QPushButton *ok_button_3;
    QLineEdit *initial_candies;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *ok_candies;

    void setupUi(QWidget *GameTheoryClass)
    {
        if (GameTheoryClass->objectName().isEmpty())
            GameTheoryClass->setObjectName(QString::fromUtf8("GameTheoryClass"));
        GameTheoryClass->resize(741, 504);
        heap_1 = new QLCDNumber(GameTheoryClass);
        heap_1->setObjectName(QString::fromUtf8("heap_1"));
        heap_1->setGeometry(QRect(50, 160, 91, 51));
        informer = new QLabel(GameTheoryClass);
        informer->setObjectName(QString::fromUtf8("informer"));
        informer->setGeometry(QRect(20, 20, 701, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(20);
        font.setItalic(false);
        informer->setFont(font);
        heap_2 = new QLCDNumber(GameTheoryClass);
        heap_2->setObjectName(QString::fromUtf8("heap_2"));
        heap_2->setGeometry(QRect(320, 160, 101, 51));
        heap_3 = new QLCDNumber(GameTheoryClass);
        heap_3->setObjectName(QString::fromUtf8("heap_3"));
        heap_3->setGeometry(QRect(570, 160, 91, 51));
        heap_button_1 = new QPushButton(GameTheoryClass);
        heap_button_1->setObjectName(QString::fromUtf8("heap_button_1"));
        heap_button_1->setGeometry(QRect(60, 110, 81, 31));
        heap_button_2 = new QPushButton(GameTheoryClass);
        heap_button_2->setObjectName(QString::fromUtf8("heap_button_2"));
        heap_button_2->setGeometry(QRect(330, 110, 81, 31));
        heap_button_3 = new QPushButton(GameTheoryClass);
        heap_button_3->setObjectName(QString::fromUtf8("heap_button_3"));
        heap_button_3->setGeometry(QRect(580, 110, 81, 31));
        number_1 = new QLineEdit(GameTheoryClass);
        number_1->setObjectName(QString::fromUtf8("number_1"));
        number_1->setGeometry(QRect(50, 260, 91, 20));
        number_2 = new QLineEdit(GameTheoryClass);
        number_2->setObjectName(QString::fromUtf8("number_2"));
        number_2->setGeometry(QRect(320, 260, 91, 20));
        number_3 = new QLineEdit(GameTheoryClass);
        number_3->setObjectName(QString::fromUtf8("number_3"));
        number_3->setGeometry(QRect(570, 260, 91, 20));
        ok_button_1 = new QPushButton(GameTheoryClass);
        ok_button_1->setObjectName(QString::fromUtf8("ok_button_1"));
        ok_button_1->setGeometry(QRect(60, 300, 75, 23));
        ok_button_2 = new QPushButton(GameTheoryClass);
        ok_button_2->setObjectName(QString::fromUtf8("ok_button_2"));
        ok_button_2->setGeometry(QRect(330, 300, 75, 23));
        ok_button_3 = new QPushButton(GameTheoryClass);
        ok_button_3->setObjectName(QString::fromUtf8("ok_button_3"));
        ok_button_3->setGeometry(QRect(580, 300, 75, 23));
        initial_candies = new QLineEdit(GameTheoryClass);
        initial_candies->setObjectName(QString::fromUtf8("initial_candies"));
        initial_candies->setGeometry(QRect(310, 410, 113, 20));
        radioButton = new QRadioButton(GameTheoryClass);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(450, 400, 82, 17));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(GameTheoryClass);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(450, 420, 82, 17));
        ok_candies = new QPushButton(GameTheoryClass);
        ok_candies->setObjectName(QString::fromUtf8("ok_candies"));
        ok_candies->setGeometry(QRect(330, 440, 75, 23));

        retranslateUi(GameTheoryClass);

        QMetaObject::connectSlotsByName(GameTheoryClass);
    } // setupUi

    void retranslateUi(QWidget *GameTheoryClass)
    {
        GameTheoryClass->setWindowTitle(QApplication::translate("GameTheoryClass", "GameTheory", 0, QApplication::UnicodeUTF8));
        informer->setText(QString());
        heap_button_1->setText(QApplication::translate("GameTheoryClass", "Delete", 0, QApplication::UnicodeUTF8));
        heap_button_2->setText(QApplication::translate("GameTheoryClass", "Delete", 0, QApplication::UnicodeUTF8));
        heap_button_3->setText(QApplication::translate("GameTheoryClass", "Delete", 0, QApplication::UnicodeUTF8));
        ok_button_1->setText(QApplication::translate("GameTheoryClass", "OK", 0, QApplication::UnicodeUTF8));
        ok_button_2->setText(QApplication::translate("GameTheoryClass", "OK", 0, QApplication::UnicodeUTF8));
        ok_button_3->setText(QApplication::translate("GameTheoryClass", "OK", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("GameTheoryClass", "Player 1", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("GameTheoryClass", "Player 2", 0, QApplication::UnicodeUTF8));
        ok_candies->setText(QApplication::translate("GameTheoryClass", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameTheoryClass: public Ui_GameTheoryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMETHEORY_H
