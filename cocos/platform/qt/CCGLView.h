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

#ifndef __CC_EGLVIEW_WIN32_H__
#define __CC_EGLVIEW_WIN32_H__

#include <QtGui/QMouseEvent>
#include <QtWidgets/QWidget>
#include <vector>

#include "CCStdC.h"
#include "platform/CCCommon.h"
#include "math/CCGeometry.h"
#include "platform/CCGLViewProtocol.h"

typedef enum {
    GLVIEW_WINDOW_MODE_FIXSIZE = 0,     // GL window with the fixed windows size
    GLVIEW_WINDOW_MODE_RESIZABLE,       // resizable GL window
}   GLViewWindowModeType;

typedef void(*ACCEL_PTRFUN)(QKeyEvent *event);

class GLWidget;

NS_CC_BEGIN

class CC_DLL GLView : public GLViewProtocol, public Ref
{
public:
    explicit GLView();
    virtual ~GLView();

public:
    static GLView* getInstance();

    /* override functions */
    virtual bool isOpenGLReady();
    virtual void end();
    virtual void swapBuffers();
    virtual void setFrameSize(float width, float height);
    virtual void setIMEKeyboardState(bool bOpen);
    virtual void setViewName(const std::string& pszViewName);

    void resize(int width, int height);
    /* 
     * Set zoom factor for frame. This method is for debugging big resolution (e.g.new ipad) app on desktop.
     */
    void setFrameZoomFactor(float fZoomFactor);
	float getFrameZoomFactor();
    void centerWindow();
//    void moveWindow(int left, int top);

    virtual void setViewPortInPoints(float x , float y , float w , float h);
    virtual void setScissorInPoints(float x , float y , float w , float h);
    
    // static function
    /**
    @brief    get the shared main open gl window
    */
    static GLView* create(const std::string& viewName);
    static GLView* create(QWidget *parent);
    static GLView* createWithWidget(QWidget* parent);
    static GLView* createWithRect(const std::string& viewName, Rect rect, float frameZoomFactor = 1.0);
    static GLView* createWithFullScreen(const std::string& viewName);

    static void purgeSharedOpenGLView();

    // Qt
    void mouseMove(QMouseEvent *event);
    void mousePress(QMouseEvent *event);
    void mouseRelease(QMouseEvent *event);
    void setAccelerometerKeyHook(ACCEL_PTRFUN func);
    QWidget * getGLWidget(void);

    void updateGL();
private:
    virtual bool _createInWidget(QWidget *parent);
//    bool initGL();
//    void destroyGL();

private:
    bool m_bIsInit;
    bool m_bCaptured;
    bool m_bSupportTouch;
    float m_fFrameZoomFactor;
    float m_fScreenScaleFactor;

    GLViewWindowModeType GLViewWindowMode;
    std::vector<Touch*> * m_pSet;
    Touch * m_pTouch;
    GLWidget* m_window;
    QWidget * m_glParentWidget;
};

NS_CC_END

#endif    // end of __CC_EGLVIEW_WIN32_H__
