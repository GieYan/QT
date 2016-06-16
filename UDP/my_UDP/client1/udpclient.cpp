#include "udpclient.h"
#include <stdlib.h>
#include <ctime>

UdpClient::UdpClient( QWidget *parent, Qt::WindowFlags  f )
    : QDialog( parent, f )
{
    setWindowTitle(tr("UDP Client"));

    QGridLayout *midLayout = new QGridLayout;
    label1 = new QLabel(tr("Input:"));
    label2 = new QLabel(tr("TimerStatus:"));
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
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(timeOut()));

    srand(time(NULL));
    port = 5555;
    status = false;
    i=0;

    udpSocket = new QUdpSocket(this);
}

UdpClient::~UdpClient()
{
}

void UdpClient::send()
{
    if(!status)
    {
        timer->start(5);
        sendButton->setText("Stop");
        status = true;
    }
    else
    {
        timer->stop();
        sendButton->setText("Send");
        status = false;
    }
    LineEdit2->setText(QString::number(timer->isActive()));
}

void UdpClient::timeOut()
{
    i = rand()%100;
    LineEdit1->setText(QString::number(i));
    QString msg = LineEdit1->text();
    udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port);

}
