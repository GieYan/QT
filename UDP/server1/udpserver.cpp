#include "udpserver.h"

UdpServer::UdpServer(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent,f)
{
    setWindowTitle(tr("Server"));
    QGridLayout *gLayout = new QGridLayout;
    label1 = new QLabel(tr("receive")) ;
    label2 = new QLabel(tr("send"));
    lineEdit1 = new QLineEdit;
    lineEdit2 = new QLineEdit;
    gLayout->addWidget(label1);
    gLayout->addWidget(lineEdit1);
    gLayout->addWidget(label2);
    gLayout->addWidget(lineEdit2);
    setLayout(gLayout);

    port = 5555;

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(port);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(valueSolve()));
}

UdpServer::~UdpServer()
{

}

void UdpServer::valueSolve()
{
    QMessageBox::information(this,tr("dd"),tr("dd"));
    int i;
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray dataGram;
        dataGram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(dataGram.data(),dataGram.size());
        lineEdit1->setText(dataGram.data());
        QString msg = lineEdit1->text();
        i =msg.toInt();
        msg = QString::number(++i);
        lineEdit2->setText(msg);
        udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port);
    }
}
