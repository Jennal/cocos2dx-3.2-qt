/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2014 Chukong Technologies Inc.
Copyright (c) 2013-2014 Zhu Delun (delun.zhu@gmail.com)

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "GLWidget.h"
#include <QtCore/QTimer>

GLWidget::GLWidget(QWidget *parent, const int width, const int height)
    : QOpenGLWidget(parent)
    , mouseMoveFunc(NULL)
    , mousePressFunc(NULL)
    , mouseReleaseFunc(NULL)
    , frameResizeFunc(NULL)
    , keyEventFunc(NULL)
{
    resize(width, height);
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
    QOpenGLWidget::initializeGL();

    CCLOG("GLWidget::initializeGL: context = %p", this->context());
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()),
                         this, SLOT(update()));
    timer->start(1000.0/60.0);
}

void GLWidget::update()
{
//    CCLOG("GLWidget::update()");
    QOpenGLWidget::update();
}

void GLWidget::setMouseMoveFunc(MOUSEEVENT_FUNCPTR func)
{
    mouseMoveFunc = func;
}

void GLWidget::setMousePressFunc(MOUSEEVENT_FUNCPTR func)
{
    mousePressFunc = func;
}

void GLWidget::setMouseReleaseFunc(MOUSEEVENT_FUNCPTR func)
{
    mouseReleaseFunc = func;
}

void
GLWidget::setResizeFunc(RESIZE_FUNCPTR func)
{
    frameResizeFunc = func;
}

void GLWidget::setKeyEventFunc(ACCEL_FUNCPTR func)
{
    keyEventFunc = func;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    //CCTRACE();
    if (mouseMoveFunc)
        mouseMoveFunc(event);

    QOpenGLWidget::mouseMoveEvent(event);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    //CCTRACE();
    if (mousePressFunc)
        mousePressFunc(event);

    QOpenGLWidget::mousePressEvent(event);
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    //CCTRACE();
    if (mouseReleaseFunc)
        mouseReleaseFunc(event);

    QOpenGLWidget::mouseReleaseEvent(event);
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
    //CCTRACE();
    if (keyEventFunc)
        keyEventFunc(e);

    QOpenGLWidget::keyPressEvent(e);
}

void GLWidget::keyReleaseEvent(QKeyEvent *e)
{
    //CCTRACE();
    if (keyEventFunc)
        keyEventFunc(e);

    QOpenGLWidget::keyReleaseEvent(e);
}

void
GLWidget::resizeEvent(QResizeEvent *event)
{
    //CCTRACE();
    if (frameResizeFunc)
        frameResizeFunc(event);

    QOpenGLWidget::resizeEvent(event);
}

