#include "udpclient.h"

UdpClient::UdpClient( QWidget *parent, Qt::WindowFlags  f )
    : QDialog( parent, f )
{
    setWindowTitle(tr("UDP Client"));

    QGridLayout *midLayout = new QGridLayout;
    label1 = new QLabel(tr("Input:"));
    label2 = new QLabel(tr("get:"));
    LineEdit1 = new QLineEdit;
    LineEdit2 = new QLineEdit;
    midLayout->addWidget(label1,0,0);
    midLayout->addWidget(LineEdit1,0,1);
    midLayout->addWidget(label2,1,0);
    midLayout->addWidget(LineEdit2,1,1);
    sendButton = new QPushButton(tr("Send"));

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(midLayout);
    vLayout->addWidget(sendButton);
    setLayout(vLayout);

    connect(sendButton,SIGNAL(clicked()),this,SLOT(send()));

    port = 5555;

    udpSocket = new QUdpSocket(this);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(acceptValue()));
    udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
}

UdpClient::~UdpClient()
{
}

void UdpClient::send()
{
    QString msg = LineEdit1->text();
    udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port);
}

void UdpClient::acceptValue()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray dataGram;
        dataGram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(dataGram.data(),dataGram.size());
        LineEdit2->setText(dataGram.data());
    }
}
