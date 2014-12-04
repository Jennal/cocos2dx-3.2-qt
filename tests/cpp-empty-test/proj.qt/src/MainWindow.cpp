#include "MainWindow.h"
#include <QMessageBox>
#include "cocos2d.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(btnClicked()));
    QObject::connect(UIMessageAdapter::getInstance(), SIGNAL(testSignal(const char*)), this, SLOT(recvCocos2dxSignal(const char*)));
}

void MainWindow::btnClicked()
{
    QMessageBox::information(NULL, "Title", "Content", QMessageBox::Ok, QMessageBox::Ok);
    UIMessageAdapter::getInstance()->push("Hello From MainWindow");
}

void MainWindow::recvCocos2dxSignal(const char* msg)
{
    pushButton->setText(msg);
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

QWidget*
MainWindow::getGLWidget()
{
    return mCocos2dWidget;
}
