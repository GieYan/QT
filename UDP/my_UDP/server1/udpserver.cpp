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
    Text = new QPushButton(tr("Text:"));
    gLayout->addWidget(label1);
    gLayout->addWidget(lineEdit1);
    gLayout->addWidget(label2);
    gLayout->addWidget(lineEdit2);
    gLayout->addWidget(Text);
    setLayout(gLayout);

    port = 5555;

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(port);
    connect(Text,SIGNAL(clicked()),this,SLOT(openText()));
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(valueSolve()));
}

UdpServer::~UdpServer()
{

}

void UdpServer::valueSolve()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray dataGram;
        dataGram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(dataGram.data(),dataGram.size());
        QDataStream in(&dataGram,QIODevice::ReadOnly);
        QFile file("data.dat");
        file.open(QIODevice::WriteOnly|QIODevice::Append);
        QDataStream out(&file);
        quint16 head;
        quint16 rand;
        in>>head>>rand;
        out<<head<<rand;
//        file.close();
        lineEdit1->setText(QString::number(head));

        ++rand;
        QString msg = QString::number(rand);
        lineEdit2->setText(msg);
    }
}

void UdpServer::openText()
{
    dataWidget = new showData;
    dataWidget->exec();
}
