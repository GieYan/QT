#ifndef UDPSERVER_H
#define UDPSERVER_H
#include <QtWidgets>
#include <QtNetwork>

class UdpServer : public QDialog
{
    Q_OBJECT

public:
    UdpServer(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~UdpServer();

    QLabel *label1;
    QLabel *label2;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;

    quint16 port;
    QUdpSocket *udpSocket;
public slots:
    void valueSolve();
};

#endif
