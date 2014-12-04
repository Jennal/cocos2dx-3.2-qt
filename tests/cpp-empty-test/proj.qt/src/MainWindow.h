#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

public:

public slots:
    void btnClicked();
    void onCocos2dxWindowMoved(int x, int y);

protected:
    void changeEvent(QEvent *e);
    virtual void closeEvent(QCloseEvent *);
    virtual void showEvent(QShowEvent *);
    virtual void moveEvent(QMoveEvent *);
};

#endif // MAINWINDOW_H
