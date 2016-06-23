#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString regexp,text;
    QStringList match;
    regexp = ui->lineEdit1->text();
    text = ui->textEdit->toPlainText();
    QRegExp rx(regexp);
    int pos = rx.indexIn(text);
    if(pos>=0)
    {
        match = rx.capturedTexts();
        ui->lineEdit2->setText(match[0]);
    }
    else
        ui->lineEdit2->setText(tr("error!no match!"));
}
