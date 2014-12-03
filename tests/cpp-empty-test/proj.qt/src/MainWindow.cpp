#include "MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(btnClicked()));
}

void MainWindow::btnClicked()
{
    QMessageBox::information(NULL, "Title", "Content", QMessageBox::Ok, QMessageBox::Ok);
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
