#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *getButton;
    QPushButton *openFileButton;
    QLabel *lineLabel;
    QLabel *fileLabel;
    QLabel *sizeLabel;
    QLabel *lenLabel;
    QLineEdit *lineEdit;
    QLineEdit *fileEdit;
    QLineEdit *sizeEdit;
    QLineEdit *lenEdit;
    QString fileDir;
    QLabel *messageLabel;
public slots:
    void get();
    void openFile();
};

#endif // WIDGET_H
