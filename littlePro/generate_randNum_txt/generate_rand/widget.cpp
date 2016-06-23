#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setFixedSize(300,200);
    getButton = new QPushButton(tr("Genet"),this);
    getButton->setGeometry(170,140,80,25);
    getButton->setEnabled(false);
    connect(getButton,SIGNAL(clicked(bool)),this,SLOT(get()));
    openFileButton = new QPushButton(tr("saveDir"),this);
    openFileButton->setGeometry(50,140,80,25);
    connect(openFileButton,SIGNAL(clicked(bool)),this,SLOT(openFile()));
    lineLabel = new QLabel(tr("Lines:"),this);
    lineEdit = new QLineEdit(this);
    fileLabel = new QLabel(tr("FileName:"),this);
    fileEdit = new QLineEdit(this);
    sizeLabel = new QLabel(tr("Size:"),this);
    sizeEdit = new QLineEdit(this);
    lenLabel = new QLabel(tr("Length:"),this);
    lenEdit = new QLineEdit(this);
    messageLabel = new QLabel;
    lineLabel->setGeometry(50,20,80,25);
    lineEdit->setGeometry(50,45,80,25);
    fileLabel->setGeometry(170,20,80,25);
    fileEdit->setGeometry(170,45,80,25);
    sizeLabel->setGeometry(50,75,80,25);
    sizeEdit->setGeometry(50,100,80,25);
    lenLabel->setGeometry(170,75,80,25);
    lenEdit->setGeometry(170,100,80,25);
    messageLabel->setGeometry(50,170,200,25);
}

Widget::~Widget()
{

}

void Widget::get()
{
    QString fileName,size;
    int lineNum,length,min,max;
    lineNum = lineEdit->text().toInt();
    fileName = fileDir + "/" + fileEdit->text() + ".txt";
    size = sizeEdit->text();
    length = lenEdit->text().toInt();
    QRegExp rx("(\\d+)([-~/|]|(\\s))(\\d+)");
    int pos = size.indexOf(rx);
    if(pos>=0)
    {
        min=rx.cap(1).toInt();
        max=rx.cap(4).toInt();
    }
    else
        messageLabel->setText(tr("error!match incorrectly,reinput size!"));

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
        messageLabel->setText(tr("error!open file failed!try again!"));
    QTextStream out(&file);
    for(int i=0;i<length;++i)
    {
        for(int j=0;j<lineNum;++j)
        {
            int n1=rand()%(max-min)+min;
            out<<n1<<" ";
        }
        out<<"\r\n";
    }
}

void Widget::openFile()
{
    fileDir = QFileDialog::getExistingDirectory(this,tr("select the dir"),"./",QFileDialog::ShowDirsOnly);
    getButton->setEnabled(true);
}
