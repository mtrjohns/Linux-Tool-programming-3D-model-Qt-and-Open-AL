/********************************************************************************
** Form generated from reading UI file 'OpenALWithQT.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENALWITHQT_H
#define UI_OPENALWITHQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenALwithQT
{
public:
    QWidget *centralWidget;
    QPushButton *PlayBattleButton;
    QPushButton *StopBattleButton;
    QPushButton *PlayGunOneButton;
    QPushButton *StopGunOneButton;
    QPushButton *PlayGunTwoButton;
    QPushButton *StopGunTwoButton;
    QPushButton *PauseGunTwoButton;
    QPushButton *PauseBattleButton;
    QPushButton *PauseGunOneButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenALwithQT)
    {
        if (OpenALwithQT->objectName().isEmpty())
            OpenALwithQT->setObjectName(QString::fromUtf8("OpenALwithQT"));
        OpenALwithQT->resize(310, 150);
        centralWidget = new QWidget(OpenALwithQT);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PlayBattleButton = new QPushButton(centralWidget);
        PlayBattleButton->setObjectName(QString::fromUtf8("PlayBattleButton"));
        PlayBattleButton->setGeometry(QRect(10, 0, 90, 32));
        StopBattleButton = new QPushButton(centralWidget);
        StopBattleButton->setObjectName(QString::fromUtf8("StopBattleButton"));
        StopBattleButton->setGeometry(QRect(210, 0, 90, 32));
        PlayGunOneButton = new QPushButton(centralWidget);
        PlayGunOneButton->setObjectName(QString::fromUtf8("PlayGunOneButton"));
        PlayGunOneButton->setGeometry(QRect(10, 40, 90, 32));
        StopGunOneButton = new QPushButton(centralWidget);
        StopGunOneButton->setObjectName(QString::fromUtf8("StopGunOneButton"));
        StopGunOneButton->setGeometry(QRect(210, 40, 90, 32));
        PlayGunTwoButton = new QPushButton(centralWidget);
        PlayGunTwoButton->setObjectName(QString::fromUtf8("PlayGunTwoButton"));
        PlayGunTwoButton->setGeometry(QRect(10, 80, 90, 32));
        StopGunTwoButton = new QPushButton(centralWidget);
        StopGunTwoButton->setObjectName(QString::fromUtf8("StopGunTwoButton"));
        StopGunTwoButton->setGeometry(QRect(210, 80, 90, 32));
        PauseGunTwoButton = new QPushButton(centralWidget);
        PauseGunTwoButton->setObjectName(QString::fromUtf8("PauseGunTwoButton"));
        PauseGunTwoButton->setGeometry(QRect(110, 80, 90, 32));
        PauseBattleButton = new QPushButton(centralWidget);
        PauseBattleButton->setObjectName(QString::fromUtf8("PauseBattleButton"));
        PauseBattleButton->setGeometry(QRect(110, 0, 90, 32));
        PauseGunOneButton = new QPushButton(centralWidget);
        PauseGunOneButton->setObjectName(QString::fromUtf8("PauseGunOneButton"));
        PauseGunOneButton->setGeometry(QRect(110, 40, 90, 32));
        OpenALwithQT->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(OpenALwithQT);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        OpenALwithQT->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OpenALwithQT);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        OpenALwithQT->setStatusBar(statusBar);

        retranslateUi(OpenALwithQT);

        QMetaObject::connectSlotsByName(OpenALwithQT);
    } // setupUi

    void retranslateUi(QMainWindow *OpenALwithQT)
    {
        OpenALwithQT->setWindowTitle(QApplication::translate("OpenALwithQT", "OpenALwithQT", 0, QApplication::UnicodeUTF8));
        PlayBattleButton->setText(QApplication::translate("OpenALwithQT", "Play Battle", 0, QApplication::UnicodeUTF8));
        StopBattleButton->setText(QApplication::translate("OpenALwithQT", "Stop Battle", 0, QApplication::UnicodeUTF8));
        PlayGunOneButton->setText(QApplication::translate("OpenALwithQT", "Play Gun 1", 0, QApplication::UnicodeUTF8));
        StopGunOneButton->setText(QApplication::translate("OpenALwithQT", "Stop Gun 1", 0, QApplication::UnicodeUTF8));
        PlayGunTwoButton->setText(QApplication::translate("OpenALwithQT", "Play Gun 2", 0, QApplication::UnicodeUTF8));
        StopGunTwoButton->setText(QApplication::translate("OpenALwithQT", "Stop Gun 2", 0, QApplication::UnicodeUTF8));
        PauseGunTwoButton->setText(QApplication::translate("OpenALwithQT", "Pause Gun 2", 0, QApplication::UnicodeUTF8));
        PauseBattleButton->setText(QApplication::translate("OpenALwithQT", "Pause Battle", 0, QApplication::UnicodeUTF8));
        PauseGunOneButton->setText(QApplication::translate("OpenALwithQT", "Pause Gun 1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenALwithQT: public Ui_OpenALwithQT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENALWITHQT_H
