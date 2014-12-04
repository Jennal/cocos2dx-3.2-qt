#include "MainWindow.h"
#include <QMessageBox>
#include <QtEvents>
#include "cocos2d.h"

#define GLFW_WIDTH 961

USING_NS_CC;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    QObject::connect(UIMessageAdapter::getInstance(), SIGNAL(cocos2dxWindowPosChanged(int, int)),
                     this, SLOT(onCocos2dxWindowMoved(int, int)));
}

void MainWindow::btnClicked()
{
    QMessageBox::information(NULL, "Title", "Content", QMessageBox::Ok, QMessageBox::Ok);
    UIMessageAdapter::getInstance()->push("Hello From MainWindow");
}

void MainWindow::onCocos2dxWindowMoved(int x, int y)
{
    int mx, my, w, h;
    this->geometry().getRect(&mx, &my, &w, &h);

    x += GLFW_WIDTH;
    if(mx == x && my == y) return;
    this->setGeometry(x, y, w, h);
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

void MainWindow::closeEvent(QCloseEvent *e)
{
    Director::getInstance()->end();
    e->accept();
}

void MainWindow::showEvent(QShowEvent *e)
{
    QMainWindow::showEvent(e);

    int x, y;
    Director::getInstance()->getOpenGLView()->getWindowPos(&x, &y);
    this->onCocos2dxWindowMoved(x, y);
}

void MainWindow::moveEvent(QMoveEvent *e)
{
    QMainWindow::moveEvent(e);

//    auto pos = e->pos();
//    Director::getInstance()->getOpenGLView()->setWindowPos(pos.x() - GLFW_WIDTH, pos.y());
}
