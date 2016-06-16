#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QtWidgets>
#include <QtNetwork>

class UdpClient : public QDialog
{
    Q_OBJECT
public:
    UdpClient( QWidget *parent=0, Qt::WindowFlags  f=0 );
    ~UdpClient();
public:
    QLabel *label1;
    QLabel *label2;
    QLineEdit* LineEdit1;
    QLineEdit *LineEdit2;
    QPushButton* sendButton;

    QUdpSocket *udpSocket;
    quint16 port;
    QTimer *timer;

    bool status;
    int i;

public slots:
    void send();
    void timeOut();
};


#endif
