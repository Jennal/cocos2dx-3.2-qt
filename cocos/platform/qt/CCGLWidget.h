/****************************************************************************
Copyright (c) 2010 cocos2d-x.org
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

#ifndef  _GL_WIDGET_H_
#define  _GL_WIDGET_H_

#include "base/CCDirector.h"
#include "platform/CCCommon.h"
#undef CursorShape
#include "CCGL.h"
#include <QtOpenGL/QGLWidget>

class QTimer;
USING_NS_CC;

typedef void(*MOUSEEVENT_FUNCPTR)(QMouseEvent *event);
typedef void(*RESIZE_FUNCPTR)(QResizeEvent* event);
typedef void(*ACCEL_FUNCPTR)(QKeyEvent *event);

class CC_DLL GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0, const int width = 800, const int height = 600);
    virtual ~GLWidget();

    void setMouseMoveFunc( MOUSEEVENT_FUNCPTR func);
    void setMousePressFunc( MOUSEEVENT_FUNCPTR func);
    void setMouseReleaseFunc( MOUSEEVENT_FUNCPTR func);
    void setResizeFunc( RESIZE_FUNCPTR func);
    void setKeyEventFunc( ACCEL_FUNCPTR func);

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    MOUSEEVENT_FUNCPTR mouseMoveFunc;
    MOUSEEVENT_FUNCPTR mousePressFunc;
    MOUSEEVENT_FUNCPTR mouseReleaseFunc;
    RESIZE_FUNCPTR frameResizeFunc;

    ACCEL_FUNCPTR keyEventFunc;
};

#endif // _GL_WIDGET_H_
