#include "showdata.h"

showData::showData()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    widget = new QTableWidget;
    widget->setRowCount(100);
    widget->setColumnCount(3);
    close = new QPushButton(tr("Close"));
    connect(close,SIGNAL(clicked(bool)),this,SLOT(accept()));
    layout->addWidget(widget);
    layout->addWidget(close);
    QFile file("data.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    quint16 a[100],b[100];
    int i=0;
    while(!file.atEnd())
    {
        in>>a[i]>>b[i];
        QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(a[i]));
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(b[i]));
        widget->setItem(i,0,item1);
        widget->setItem(i,1,item2);
        ++i;
    }
    file.close();
}
