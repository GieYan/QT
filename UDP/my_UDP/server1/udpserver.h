#ifndef UDPSERVER_H
#define UDPSERVER_H
#include <QtWidgets>
#include <QtNetwork>
#include "showdata.h"

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
    QPushButton *Text;

    quint16 port;
    QUdpSocket *udpSocket;
    showData *dataWidget;
public slots:
    void valueSolve();
    void openText();
};

#endif
