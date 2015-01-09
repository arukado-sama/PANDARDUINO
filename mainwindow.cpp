#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //initialize main window
    initWindow();

    //initialize some variables for first use
    initFirstUse();

    //restore old settings
    restoreSettings();

    //initalize upload process
    initProcess();

    //connects
    connect(procUpload,SIGNAL(readyReadStandardOutput()),this,SLOT(affichUpload()));
    connect(procUpload,SIGNAL(readyReadStandardError()),this,SLOT(affichUpload()));
    connect(ui->buttonExit, SIGNAL(clicked()), qApp, SLOT(quit()));

    //initialize build directory if there is an argument
    initBuildDirectory();

    //initalize sockets
    initSocket();
}


MainWindow::~MainWindow()
{
    //kill upload process
    procUpload->kill();

    //delete upload process
    delete procUpload;

    //abort sockets
    udpSocket->abort();
    dataSocket->abort();
    alreadySocket->abort();

    //delete sockets
    delete udpSocket;
    delete dataSocket;
    delete alreadySocket;

    //delete settings
    delete settings;

    //if connected
    if(connection==1)
    {
        //close port
        port->close();

        //delete port
        delete port;
    }

    //close upload information window
    if(infoUpload.isVisible())
        infoUpload.close();

    //close application
    delete ui;
}



//_____________________ BUTTONS ______________________ //


    ///----------------buttonBuild--------------///

    //.hex file selection button


void MainWindow::on_buttonBuild_clicked()
{
    //set up .hex file dialog window
    dialogBuild.setFileMode(QFileDialog::AnyFile);
    dialogBuild.setWindowTitle("Open .hex file");
    dialogBuild.setNameFilter("hex file (*.hex)");

    //if .hex file selected
    if(dialogBuild.exec()==1)
    {
        //save .hex complete file path
        hexName=dialogBuild.selectedFiles().first();

        //display .hex complete file path
        ui->buildLabel->setText(hexName);

        //save .hex complete directory path
        buildDir=dialogBuild.directory().path();

        //if combo boxes index is not the first for each and if there is no connection
        if((ui->cardComboBox->currentIndex()!=0)&&(ui->speedComboBox->currentIndex()!=0)&&(ui->portComboBox->currentIndex()!=0))
        {
            //enable upload button
            ui->buttonUpload->setEnabled(1);
        }

        //display panda message
        ui->pandaLabel->setText(".hex file selected ! *eating bamboo*");
    }

    else
    {
        //set up buttons and labels at default state
        ui->buttonUpload->setEnabled(0);
        ui->buildLabel->setText("...");
        ui->pandaLabel->setText("Hi ! Welcome to PANDARDUINO, I'm Master Panda ! Nice to meet you !");

        //set .hex complete file path at default
        hexName="...";

        //set .hex complete directory path at default
        buildDir="0";
    }

    //save .hex complete file path into settings file
    settings->setValue("FILE/file",hexName);

    //save .hex complete directory path into settings file
    settings->setValue("FILE/directory",buildDir);
}


    ///------------------buttonUpload------------///

    //upload button


void MainWindow::on_buttonUpload_clicked()
{  
    //if connected
    if(connection==1)
    {
        //auto disconnection
        autoDisconnect();

        //there was a connection before
        oldconnection=1;
    }

    //temporary disable interface
    ui->buttonUpload->setEnabled(0);
    ui->buttonConnect->setEnabled(0);
    ui->cardComboBox->setEnabled(0);
    ui->speedComboBox->setEnabled(0);
    ui->portComboBox->setEnabled(0);
    ui->optionsLine->setEnabled(0);

    //set up upload information window
    infoUpload.setWindowTitle("Upload information");
    infoUpload.setMinimumSize(800,400);
    infoUpload.setStyleSheet("background-color: black; color: white;");

    //show upload information window
    infoUpload.show();

    //raise upload information window
    infoUpload.raise();

    //start upload process
    procUpload->start("avrdude -q "+ui->optionsLine->text()+" -p "+ui->cardComboBox->currentText()+" -c arduino -P "+ui->portComboBox->currentText()+" -b "+ui->speedComboBox->currentText()+" -U flash:w:"+hexName);

    //display panda message
    ui->pandaLabel->setText("Upload complete ! *dreaming*");

    //wait 2 sec
    delay(2000);

    //if disconnected and there was a connection before
    if((connection==0)&&(oldconnection==1))
    {
        //auto connection
        autoConnect();

        //reset old connection watcher
        oldconnection=0;
    }

    //if .hex complete directory path at default
    if(buildDir!="0")

        //enable upload button
        ui->buttonUpload->setEnabled(1);

    //enable interface
    ui->buttonConnect->setEnabled(1);
    ui->cardComboBox->setEnabled(1);
    ui->speedComboBox->setEnabled(1);
    ui->portComboBox->setEnabled(1);
    ui->optionsLine->setEnabled(1);
}


    ///----------------buttonConnect-------------///

    //connection button


void MainWindow::on_buttonConnect_clicked()
{
    //if disconnected
    if(connection==0)

        //auto connection
        autoConnect();

    //if connected
    else
        //auto disconnection
        autoDisconnect();
}


    ///----------------buttonClear----------------///

    //clear textbrowser button


void MainWindow::on_buttonClear_clicked()
{
    //clear card dialog text browser
    ui->cardDialog->clear();

    //ask for user messages deletion
    int answer = QMessageBox::question(this,"Clear","Do you want clear your messages ?", QMessageBox::Yes | QMessageBox::No);

    //if positive answer
    if (answer == QMessageBox::Yes)
    {
        //delete all user lines
        for(int i=0; i<cpt; i++)
        {
            qDeleteAll(ui->lineDialog->selectedItems());
            QString line="TEXT/line"+QString::number(i);
            settings->remove(line);
        }

        //reset line counter
        cpt=0;

        //save counter into settings file
        settings->setValue("PARAMETERS/cpt",cpt);
    }

    //clear line edit
    ui->lineEdit->clear();

    //if there is no registered messages
    if(!((ui->cardDialog->toPlainText()!="")||(ui->lineDialog->currentIndex()!=ui->lineDialog->rootIndex())))

        //disable clear button
        ui->buttonClear->setEnabled(0);
}


    ///-----------------buttonAbout-----------------///

    //about window button


void MainWindow::on_buttonAbout_clicked()
{
    //show about information box
    QMessageBox::information(this, "About", QString::fromUtf8(reinterpret_cast<const char*>("This is PANDARDUINO 0.1\n\n©2014 Created by :\n\nClément JARDIN (aka Arukādo)\n<arukaado-sama@gmail.com>\n\nEwans BROUCH (aka Natsulo)\n<ewans.brouch@gmail.com>")));
}



//_____________________________COMBOBOXES______________________________//


    ///-----------------------cardComboBox-----------------///

    //card selection combo box


void MainWindow::on_cardComboBox_currentIndexChanged(const QString &arg1)
{
    //if card combo box index is "Select card" and other combo boxes index is the first for each
    if((arg1!="Select card")&&(ui->speedComboBox->currentIndex()!=0)&&(ui->portComboBox->currentIndex()!=0))
    {
        //enable connection button
        ui->buttonConnect->setEnabled(1);

        //if .hex complete directory path isn't at default
        if(buildDir!="0")

            //enable upload button
            ui->buttonUpload->setEnabled(1);
    }

    else
    {
        //set up buttons at default
        ui->buttonUpload->setEnabled(0);

        //if there is no connection
        if(connection==0)

            //disable connection button
            ui->buttonConnect->setEnabled(0);
    }

    //save current card combo box index into settings file
    settings->setValue("PARAMETERS/card",ui->cardComboBox->currentIndex());
}


    ///---------------------speedComboBox-------------///

    //baudrate selection combo box


void MainWindow::on_speedComboBox_currentIndexChanged(const QString &arg1)
{
    //if card speed combo box index is "Select speed" and other combo boxes index is the first for each
    if((arg1!="Select speed")&&(ui->cardComboBox->currentIndex()!=0)&&(ui->portComboBox->currentIndex()!=0))
    {
        //enable connection button
        ui->buttonConnect->setEnabled(1);

        //if .hex complete directory path isn't at default
        if(buildDir!="0")

            //enable upload button
            ui->buttonUpload->setEnabled(1);
    }

    else
    {
        //set up buttons at default
        ui->buttonUpload->setEnabled(0);

        //if there is no connection
        if(connection==0)

            //disable connection button
            ui->buttonConnect->setEnabled(0);
    }

    //save current speed combo box index into settings file
    settings->setValue("PARAMETERS/speed",ui->speedComboBox->currentIndex());
}


    ///---------------------portComboBox---------------///

    //port selection combo box


void MainWindow::on_portComboBox_currentIndexChanged(const QString &arg1)
{
    //if card port combo box index is "Select port" and other combo boxes index is the first for each
    if((arg1!="Select port")&&(ui->cardComboBox->currentIndex()!=0)&&(ui->speedComboBox->currentIndex()!=0))
    {
        //enable connection button
        ui->buttonConnect->setEnabled(1);

        //if .hex complete directory path isn't at default
        if(buildDir!="0")

            //enable upload button
            ui->buttonUpload->setEnabled(1);
    }

    else
    {
        //set up buttons at default
        ui->buttonUpload->setEnabled(0);

        //if there is no connection
        if(connection==0)

            //disable connection button
            ui->buttonConnect->setEnabled(0);
    }

    //save current port combo box index into settings file
    settings->setValue("PARAMETERS/port",ui->portComboBox->currentIndex());
}


    ///---------------textComboBox-------------///

    //text input option combo box


void MainWindow::on_textComboBox_currentIndexChanged(int index)
{
    //switch text combo box index and return input text option
    switch(index)
    {
        case 0:state="\r";statevar=0;break;
        case 1:state="\n";statevar=0;break;
        case 2:state="\n\r";statevar=0;break;
        case 3:state="";statevar=0;break;
        case 4:statevar=1;break;
    }
}



//___________________________LABELS_______________________________//


    ///----------------------affichUpload---------------------///

    //upload display text browser


void MainWindow::affichUpload()
{
    //save all standard upload output
    QString uploadStandard = QString::fromUtf8(reinterpret_cast<const char*>(procUpload->readAllStandardOutput().constData()));

    //display all standard upload output
    infoUpload.append(uploadStandard);

    //save all standard upload errors
    QString uploadError = QString::fromUtf8(reinterpret_cast<const char*>(procUpload->readAllStandardError().constData()));

    //display all standard upload errors
    infoUpload.append(uploadError);
}


    ///---------------------lineEdit---------------------///

    //user messages line edit


void MainWindow::on_lineEdit_returnPressed()
{
    //if line edit isn't empty
    if(ui->lineEdit->text()!="")
    {
        //insert new line
        ui->lineDialog->insertItem(cpt,ui->lineEdit->text());

        //set new line as current line
        ui->lineDialog->setCurrentItem(ui->lineDialog->item(cpt));

        //save line number
        QString line="TEXT/line"+QString::number(cpt);

        //save line into settings file
        settings->setValue(line,ui->lineDialog->currentItem()->text());

        //increment line counter
        cpt++;

        //save line counter into settings file
        settings->setValue("PARAMETERS/cpt",cpt);
    }

    //if card dialog text browser isn't empty
    if((ui->cardDialog->toPlainText()!="")||(ui->lineDialog->currentIndex()!=ui->lineDialog->rootIndex()))

        //enable clear button
        ui->buttonClear->setEnabled(1);
}



//________________________________SIGNALS_____________________________//


    ///---------------------sendData------------------///

    //data transmission signal


void MainWindow::sendData()
{
    //will contain line edit text
    QString chara;

    //if line input isn't hexadecimal
    if(statevar==0)

        //save line edit text and input type
        chara = state+ui->lineEdit->text();

    //if line input is hexadecimal
    if(statevar==1)

        //save line edit text
        chara = ui->lineEdit->text();

    //if port is opened and line edit text isn't empty
    if((port->isOpen())&&(chara!=""))
    {
        //write line edit text into port
        port->write(chara.toAscii());
    }

    //clear line edit
    ui->lineEdit->clear();
}


    ///---------------------readData-----------------///

    ////data reception signal


void MainWindow::readData()
{
    //erase old port buffer
    port->flush();

    //save port readAll output
    QByteArray data = port->readAll();

    //if line input isn't hexadecimal
    if(statevar==0)

        //insert line edit text into card dialog text browser
        ui->cardDialog->insertPlainText(data);

    //if line input is hexadecimal
    if(statevar==1)

        //convert and insert line edit text into card dialog text browser
        ui->cardDialog->insertPlainText(QByteArray::fromHex(data).data());

    //set vertical card dialog text browser scroll bar at maximum
    ui->cardDialog->verticalScrollBar()->setValue(ui->cardDialog->verticalScrollBar()->maximum());

    //if card dialog text browser isn't empty
    if(ui->cardDialog->toPlainText()!="")

        //enable clear button
        ui->buttonClear->setEnabled(1);
}



//_______________________________OTHERS________________________________//


    ///-----------------------getBaudRate----------------------///

    //return the choosen baudRate


BaudRateType MainWindow::getBaudRateFromString(QString baudRate)
{
    //save selected baudrate
    int speed = baudRate.toInt();

    //switch baudrate and return baudrate as a baudratetype variable
    switch(speed)
    {
        case(50):return BAUD50;
        case(75):return BAUD75;
        case(110):return BAUD110;
        case(134):return BAUD134;
        case(150):return BAUD150;
        case(200):return BAUD200;
        case(300):return BAUD300;
        case(600):return BAUD600;
        case(1200):return BAUD1200;
        case(1800):return BAUD1800;
        case(2400):return BAUD2400;
        case(4800):return BAUD4800;
        case(9600):return BAUD9600;
        case(19200):return BAUD19200;
        case(38400):return BAUD38400;
        case(57600):return BAUD57600;
        case(115200):return BAUD115200;
        case(230400):return BAUD230400;
        case(460800):return BAUD460800;
        case(576000):return BAUD576000;
        case(921600):return BAUD921600;
        default:return BAUD9600;
    }
}


///-----------------------optionsLine----------------------///

    //save upload options


void MainWindow::on_optionsLine_textChanged(const QString &arg1)
{
    //save upload options into settings file
    settings->setValue("PARAMETERS/options",arg1);
}


///-----------------------lineDialog----------------------///

    //identify current lineDialog object


void MainWindow::on_lineDialog_clicked(const QModelIndex &index)
{
    //set line edit text as current user message
    ui->lineEdit->setText(ui->lineDialog->item(index.row())->text());
}


///-----------------------autoConnect----------------------///

    //auto connection


void MainWindow::autoConnect()
{
        //set up port
        port = new QextSerialPort();
        port->setPortName(ui->portComboBox->currentText());
        port->setBaudRate(getBaudRateFromString(ui->speedComboBox->currentText()));
        port->setParity(PAR_NONE);//parité
        port->setStopBits(STOP_1);//nombre de bits de stop
        port->setDataBits(DATA_8);//nombre de bits de données
        port->setFlowControl(FLOW_OFF);//pas de contrôle de flux
        port->open(QextSerialPort::ReadWrite);

        //connect read data with readyRead signal
        connect(port,SIGNAL(readyRead()), this, SLOT(readData()));

        //connect sent data with returnPressed signal
        connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(sendData()));

        //set up buttons and labels
        ui->buttonConnect->setText("Disconnect");
        ui->lineEdit->setEnabled(1);
        ui->lineDialog->setEnabled(1);
        ui->textComboBox->setEnabled(1);

        //connection
        connection=1;

        //erase old port buffer
        port->flush();

        //display panda message
        ui->pandaLabel->setText("Connected ! *waking up*");
}


///-----------------------autoDisconnect----------------------///

    //auto disconnection


void MainWindow::autoDisconnect()
{
        //if port is opened
        if(port->isOpen())
        {
            //close port
            port->close();

            //delete port
            delete port;
        }

        //set up buttons and labels for a new connection
        ui->buttonConnect->setText("Connect");
        ui->lineEdit->clear();
        ui->lineEdit->setEnabled(0);
        ui->textComboBox->setEnabled(0);
        ui->lineDialog->setEnabled(0);

        //no connection
        connection=0;

        //display panda message
        ui->pandaLabel->setText("Disconnected ! *sleeping*");

        if((ui->cardComboBox->currentIndex()!=0)&&(ui->speedComboBox->currentIndex()!=0)&&(ui->portComboBox->currentIndex()!=0))
        {
            ui->buttonConnect->setEnabled(1);

            if(buildDir!="0")
                ui->buttonUpload->setEnabled(1);
        }

        else
        {
            ui->buttonUpload->setEnabled(0);
            ui->buttonConnect->setEnabled(0);
        }
}


///-----------------------delay----------------------///

    //delay (milliseconds)


void MainWindow::delay(int ms)
{
    QEventLoop eventLoop;
    QTimer::singleShot (ms, &eventLoop, SLOT (quit ()));
    eventLoop.exec ();
}


///-----------------------processPendingDatagrams----------------------///

    //will be perform when there are pending datagrams


void MainWindow::processPendingDatagrams()
{
    //if there are pending datagrams
    if(udpSocket->hasPendingDatagrams())
    {
        //Data char creation
        char Data[500];

        //read datagram and put it in Data
        udpSocket->readDatagram(Data, 500);

        //convert Data
        QString receivedData = QString(Data);

        //if the application is already opened
        if(receivedData=="alreadyopen")
        {
            //exit application
            ui->buttonExit->click();
        }

        //if the application isn't already opened
        if(receivedData!="alreadyopen")
        {
            //focus on application window
            system("wmctrl -Fa PANDARDUINO");

            //send alreadyopen to the other application instance
            alreadySocket->writeDatagram("alreadyopen", strlen("alreadyopen")+1,QHostAddress::LocalHost, 45454);

            //set .hex complete directory path
            buildDir=receivedData;

            //set .hex complete file path
            hexName=receivedData+"/build-cli/output.hex";

            //display .hex complete directory path
            ui->buildLabel->setText(hexName);

            //save .hex complete file path into settings file
            settings->setValue("FILE/file",hexName);

            //save .hex complete directory path into settings file
            settings->setValue("FILE/directory",buildDir);

            //if combo boxes index is not the first for each and if there is no connection
            if((ui->cardComboBox->currentIndex()!=0)&&(ui->speedComboBox->currentIndex()!=0)&&(ui->portComboBox->currentIndex()!=0))
            {
                //enable upload button
                ui->buttonUpload->setEnabled(1);
                on_buttonUpload_clicked();
            }
        }
    }
}


void MainWindow::initWindow()
{
    //hide resize and close buttons

    Qt::WindowFlags wFlags = this->windowFlags();

    if(Qt::WindowCloseButtonHint == (wFlags & Qt::WindowCloseButtonHint))
    {
        wFlags = wFlags ^ Qt::WindowCloseButtonHint;
        this->setWindowFlags(wFlags);
    }

    if(Qt::WindowMaximizeButtonHint == (wFlags & Qt::WindowMaximizeButtonHint))
    {
        wFlags = wFlags ^ Qt::WindowMaximizeButtonHint;
        this->setWindowFlags(wFlags);
    }

    //resize application window
    setMinimumSize(570,660);
    setMaximumSize(570,660);

    //set application icon
    QIcon icon("/usr/share/icons/pandarduino/pandarduino.ico");
    setWindowIcon(icon);

    //set window logo
    QLabel *logo = new QLabel(this);
    logo->setPixmap(QPixmap("/usr/share/icons/pandarduino/pandarduino.jpg"));

    //setting up UI
    ui->setupUi(this);
}


void MainWindow::initFirstUse()
{
    //no connection
    connection=0;
    oldconnection=0;

    //.hex file path initialization (first use)
    buildDir="0";

    //.hex file initialization (first use)
    hexName="...";
    ui->buildLabel->setText(hexName);

    //line counter initialization (first use)
    cpt=0;

    //text input initialization (first use)
    ui->textComboBox->setCurrentIndex(3);

    // buttons / combo boxes initialization
    ui->buttonUpload->setEnabled(0);
    ui->lineEdit->setEnabled(0);
    ui->buttonConnect->setEnabled(0);
    ui->buttonClear->setEnabled(0);
    ui->textComboBox->setEnabled(0);
    ui->lineDialog->setEnabled(0);

    //port enumerator
    QextSerialEnumerator enumerator;

    //port list creation
    QList<QextPortInfo> ports = enumerator.getPorts();

    //add all avalaible ports to the list
    for(int i=0; i<ports.size(); i++)
        ui->portComboBox->addItem(ports.at(i).physName);
}


void MainWindow::restoreSettings()
{
    //settings restoration

    //settings file instantiation
    settings = new QSettings("pandarduino","pandarduino");

    if((settings->contains("PARAMETERS/card")))
        ui->cardComboBox->setCurrentIndex(settings->value("PARAMETERS/card").toInt());

    if((settings->contains("PARAMETERS/speed")))
        ui->speedComboBox->setCurrentIndex(settings->value("PARAMETERS/speed").toInt());

    if((settings->contains("PARAMETERS/port")))
        ui->portComboBox->setCurrentIndex(settings->value("PARAMETERS/port").toInt());

    if((settings->contains("PARAMETERS/cpt")))
        cpt=settings->value("PARAMETERS/cpt").toInt();

    for(int i=0; i<cpt; i++)
    {
        if((settings->contains("TEXT/line"+QString::number(i))))
        {
            QString line="TEXT/line"+QString::number(i);
            ui->lineDialog->insertItem(i,settings->value(line).toString());
        }
    }

    if((settings->contains("FILE/file")))
    {
        ui->buildLabel->setText(settings->value("FILE/file").toString());
        hexName=settings->value("FILE/file").toString();
    }

    if((settings->contains("FILE/directory")))
        buildDir=settings->value("FILE/directory").toString();

    if((settings->contains("PARAMETERS/options")))
        ui->optionsLine->setText(settings->value("PARAMETERS/options").toString());

    ui->lineDialog->setCurrentItem(ui->lineDialog->item(cpt-1));

    if(ui->portComboBox->currentText()=="")
            ui->portComboBox->setCurrentIndex(0);

    if(buildDir!="0")
        dialogBuild.setDirectory(buildDir);

    else
        dialogBuild.setDirectory("/");

    if((ui->cardComboBox->currentIndex()!=0)&&(ui->speedComboBox->currentIndex()!=0)&&(ui->portComboBox->currentIndex()!=0)&&(buildDir!="0"))
    {
        //enable upload button
        ui->buttonUpload->setEnabled(1);
    }

    if(ui->lineDialog->currentIndex()!=ui->lineDialog->rootIndex())

        //enable clear button
        ui->buttonClear->setEnabled(1);
}


void MainWindow::initBuildDirectory()
{
    //if there is 2 arguments
    if(QCoreApplication::arguments().length()==2)
    {
        //save 2nd argument (buildDir)
        QString arg = QCoreApplication::arguments().at(1);

        //set .hex complete directory path
        buildDir=arg;

        //set .hex complete file path
        hexName=arg+"/build-cli/output.hex";

        //display .hex complete file path
        ui->buildLabel->setText(hexName);

        //save .hex complete file path into settings file
        settings->setValue("FILE/file",hexName);

        //save .hex complete directory path into settings file
        settings->setValue("FILE/directory",buildDir);
    }
}


void MainWindow::initProcess()
{
    //upload process creation
    procUpload = new QProcess();

    //set upload process channel mode
    procUpload->setProcessChannelMode(QProcess::MergedChannels);
}


void MainWindow::initSocket()
{
    //socket creation
    udpSocket = new QUdpSocket(this);
    alreadySocket = new QUdpSocket(this);
    dataSocket = new QUdpSocket(this);

    //if there is 2 arguments
    if(QCoreApplication::arguments().length()==2)
    {
        //save argument 1 (buildDir)
        QString newarg = QCoreApplication::arguments().at(1);

        //convert argument
        const char *newData=newarg.toStdString().c_str();

        //send buildDir to pandarduino
        dataSocket->writeDatagram(newData, strlen(newData)+1,QHostAddress::LocalHost, 45454);
    }

    //socket binding
    udpSocket->bind(45454, QUdpSocket::ShareAddress);

    //connect socket and pending datagrams slot
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
}
