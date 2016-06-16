#ifndef SHOWDATA_H
#define SHOWDATA_H
#include <QtWidgets>

class showData : public QDialog
{
public:
    showData();
    QTableWidget *widget;
    QPushButton *close;
};

#endif // SHOWDATA_H
