/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Mar 17 08:30:12 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *buttonUpload;
    QComboBox *cardComboBox;
    QPushButton *buttonExit;
    QComboBox *speedComboBox;
    QTextBrowser *cardDialog;
    QLineEdit *lineEdit;
    QPushButton *buttonClear;
    QComboBox *portComboBox;
    QPushButton *buttonConnect;
    QPushButton *buttonBuild;
    QLabel *buildLabel;
    QPushButton *buttonAbout;
    QLabel *pandaLabel;
    QComboBox *textComboBox;
    QLineEdit *optionsLine;
    QLabel *label;
    QListWidget *lineDialog;
    QFrame *line;
    QFrame *line_2;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(572, 669);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        buttonUpload = new QPushButton(centralWidget);
        buttonUpload->setObjectName(QString::fromUtf8("buttonUpload"));
        buttonUpload->setGeometry(QRect(420, 110, 121, 27));
        buttonUpload->setStyleSheet(QString::fromUtf8(""));
        cardComboBox = new QComboBox(centralWidget);
        cardComboBox->setObjectName(QString::fromUtf8("cardComboBox"));
        cardComboBox->setGeometry(QRect(30, 110, 121, 27));
        cardComboBox->setStyleSheet(QString::fromUtf8(""));
        buttonExit = new QPushButton(centralWidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        buttonExit->setGeometry(QRect(420, 600, 121, 27));
        buttonExit->setStyleSheet(QString::fromUtf8(""));
        speedComboBox = new QComboBox(centralWidget);
        speedComboBox->setObjectName(QString::fromUtf8("speedComboBox"));
        speedComboBox->setGeometry(QRect(290, 110, 121, 27));
        speedComboBox->setStyleSheet(QString::fromUtf8(""));
        cardDialog = new QTextBrowser(centralWidget);
        cardDialog->setObjectName(QString::fromUtf8("cardDialog"));
        cardDialog->setGeometry(QRect(30, 200, 511, 221));
        cardDialog->setStyleSheet(QString::fromUtf8(""));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 560, 381, 27));
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        buttonClear = new QPushButton(centralWidget);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        buttonClear->setGeometry(QRect(30, 600, 121, 27));
        buttonClear->setStyleSheet(QString::fromUtf8(""));
        portComboBox = new QComboBox(centralWidget);
        portComboBox->setObjectName(QString::fromUtf8("portComboBox"));
        portComboBox->setGeometry(QRect(160, 110, 121, 27));
        portComboBox->setStyleSheet(QString::fromUtf8(""));
        buttonConnect = new QPushButton(centralWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));
        buttonConnect->setGeometry(QRect(420, 150, 121, 27));
        buttonConnect->setStyleSheet(QString::fromUtf8(""));
        buttonBuild = new QPushButton(centralWidget);
        buttonBuild->setObjectName(QString::fromUtf8("buttonBuild"));
        buttonBuild->setGeometry(QRect(30, 50, 98, 31));
        buttonBuild->setStyleSheet(QString::fromUtf8(""));
        buildLabel = new QLabel(centralWidget);
        buildLabel->setObjectName(QString::fromUtf8("buildLabel"));
        buildLabel->setGeometry(QRect(140, 55, 411, 21));
        buildLabel->setStyleSheet(QString::fromUtf8(""));
        buttonAbout = new QPushButton(centralWidget);
        buttonAbout->setObjectName(QString::fromUtf8("buttonAbout"));
        buttonAbout->setGeometry(QRect(210, 600, 131, 27));
        buttonAbout->setStyleSheet(QString::fromUtf8(""));
        pandaLabel = new QLabel(centralWidget);
        pandaLabel->setObjectName(QString::fromUtf8("pandaLabel"));
        pandaLabel->setGeometry(QRect(90, 10, 491, 20));
        pandaLabel->setStyleSheet(QString::fromUtf8(""));
        textComboBox = new QComboBox(centralWidget);
        textComboBox->setObjectName(QString::fromUtf8("textComboBox"));
        textComboBox->setGeometry(QRect(30, 560, 121, 27));
        textComboBox->setStyleSheet(QString::fromUtf8(""));
        optionsLine = new QLineEdit(centralWidget);
        optionsLine->setObjectName(QString::fromUtf8("optionsLine"));
        optionsLine->setGeometry(QRect(90, 150, 321, 27));
        optionsLine->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 140, 61, 41));
        label->setStyleSheet(QString::fromUtf8(""));
        lineDialog = new QListWidget(centralWidget);
        lineDialog->setObjectName(QString::fromUtf8("lineDialog"));
        lineDialog->setGeometry(QRect(30, 430, 511, 121));
        lineDialog->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 90, 581, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 180, 581, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        buttonUpload->raise();
        cardComboBox->raise();
        buttonExit->raise();
        speedComboBox->raise();
        cardDialog->raise();
        lineEdit->raise();
        buttonClear->raise();
        portComboBox->raise();
        buttonConnect->raise();
        buttonBuild->raise();
        buildLabel->raise();
        buttonAbout->raise();
        textComboBox->raise();
        optionsLine->raise();
        label->raise();
        lineDialog->raise();
        pandaLabel->raise();
        line->raise();
        line_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 572, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        buttonUpload->setText(QApplication::translate("MainWindow", "Upload", 0, QApplication::UnicodeUTF8));
        cardComboBox->clear();
        cardComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select card", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "32UC3A0512", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA128A4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA64A4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA32A4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA16A4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA256A3B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA256A3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA192A3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA128A3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA64A3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA256A1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA192A1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA128A1REVD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA128A1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATXMEGA64A1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA6450", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA3250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA645", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA325", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATmega8U2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATmega16U2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATmega32U2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90USB82", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90USB162", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90USB1287", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90USB1286", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90USB647", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90USB646", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATmega32U4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny84", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny44", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA128RFA1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA2561", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA2560", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA1281", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA1280", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA640", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny85", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90PWM3B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90PWM2B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90PWM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90PWM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny4313", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny2313", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA328P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "attiny88", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA168P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA168", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA88P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA88", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA48", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATTINY861", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATTINY461", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATTINY261", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATTINY26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA8535", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA8515", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA161", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA6490", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA649", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA3290P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA3290", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA329P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA329", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA169", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA163", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA162", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA1284P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA644P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA644", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATmega324PA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA324P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA164P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90CAN32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90CAN64", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90CAN128", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA128", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA64", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATMEGA103", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S8535", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S8515", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S4434", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S4433", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S2343", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S2333", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S2313", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S4414", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AT90S1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ATtiny11", 0, QApplication::UnicodeUTF8)
        );
        buttonExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        speedComboBox->clear();
        speedComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select speed", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "75", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "134", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "150", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "300", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "230400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "460800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "576000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "921600", 0, QApplication::UnicodeUTF8)
        );
        buttonClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        portComboBox->clear();
        portComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select port", 0, QApplication::UnicodeUTF8)
        );
        buttonConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        buttonBuild->setText(QApplication::translate("MainWindow", "Open .hex", 0, QApplication::UnicodeUTF8));
        buildLabel->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        buttonAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        pandaLabel->setText(QApplication::translate("MainWindow", "Hi ! Welcome to PANDARDUINO, I'm Master Panda ! Nice to meet you !", 0, QApplication::UnicodeUTF8));
        textComboBox->clear();
        textComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "LF line end", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CR line end", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CR, LF line end", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "No line end", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Hex input", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Upload\n"
"options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
