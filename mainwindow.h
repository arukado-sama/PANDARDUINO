#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QProcess>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <qextserialenumerator.h>
#include <qextserialport.h>
#include <qextserialport_p.h>
#include <QScrollBar>
#include <QFile>
#include <QTextStream>
#include <QSettings>
#include <QTextBrowser>
#include <QTimer>
#include <unistd.h>
#include <stdio.h>
#include <qudpsocket.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_buttonUpload_clicked();

    void on_cardComboBox_currentIndexChanged(const QString &arg1);

    void on_speedComboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_returnPressed();

    void on_buttonClear_clicked();

    void affichUpload();

    void sendData();

    void readData();

    void on_portComboBox_currentIndexChanged(const QString &arg1);

    void on_buttonConnect_clicked();

    void on_buttonBuild_clicked();

    void on_buttonAbout_clicked();

    void on_textComboBox_currentIndexChanged(int index);

    void on_optionsLine_textChanged(const QString &arg1);

    void on_lineDialog_clicked(const QModelIndex &index);

    void processPendingDatagrams();


private:
    Ui::MainWindow *ui;

    //initialize window
    void initWindow();

    //initialize buttons
    void initFirstUse();

    //initialize .hex directory if there is a 3rd argument
    void initBuildDirectory();

    //initalize processes
    void initProcess();

    //initialize sockets
    void initSocket();

    //restore settings
    void restoreSettings();

    //auto connection function
    void autoConnect();

    //auto connection function
    void autoDisconnect();

    //delay function
    void delay(int ms);

    //return the choosen baudRate
    BaudRateType getBaudRateFromString(QString baudRate);

    //upload information window
    QTextBrowser infoUpload;

    //complete path of the .hex file
    QString hexName;

    //input configuration
    QString state;

    //complete path of the .hex directory
    QString buildDir;

    //.hex file dialog window
    QFileDialog dialogBuild;

    //upload process
    QProcess *procUpload;

    //communication port
    QextSerialPort *port;

    //settings file object
    QSettings *settings;

    //0 if disconnected, 1 if connected
    unsigned char connection;

    //1 if there was a connection before, else 0
    unsigned char oldconnection;

    //1 if hexadecimal display
    int statevar;

    //line counter
    int cpt;

    //main socket
    QUdpSocket *udpSocket;

    //build directory socket
    QUdpSocket *dataSocket;

    //already opened socket
    QUdpSocket *alreadySocket;
};

#endif // MAINWINDOW_H
