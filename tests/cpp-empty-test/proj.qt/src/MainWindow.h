#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

public:
    QWidget* getGLWidget(void);

protected:
    void changeEvent(QEvent *e);
};

#endif // MAINWINDOW_H
