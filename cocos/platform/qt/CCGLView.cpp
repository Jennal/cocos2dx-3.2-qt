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

#include "CCGLView.h"
#include "base/ccMacros.h"
#include "base/CCDirector.h"
#include "base/CCTouch.h"
//#include "touch_dispatcher/CCTouchDispatcher.h"
#include "base/CCIMEDispatcher.h"
//#include "keypad_dispatcher/CCKeypadDispatcher.h"
//#include "support/CCPointExtension.h"
#include "base/CCEvent.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventKeyboard.h"
#include "base/CCEventMouse.h"
#include "CCApplication.h"

#include "CCGLWidget.h"

/// Qt
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QVBoxLayout>

NS_CC_BEGIN

//////////////////////////////////////////////////////////////////////////
// impliment GLView
//////////////////////////////////////////////////////////////////////////
static GLView* s_pMainWindow = NULL;

static void mouseMove(QMouseEvent *event)
{
    do {
        CC_BREAK_IF(s_pMainWindow == NULL);
        s_pMainWindow->mouseMove(event);
    } while (false);
    return;
}

static void mousePress(QMouseEvent *event)
{
    do {
        CC_BREAK_IF(s_pMainWindow == NULL);
        s_pMainWindow->mousePress(event);
    } while (false);
    return;
}

static void mouseRelease(QMouseEvent *event)
{
    do {
        CC_BREAK_IF(s_pMainWindow == NULL);
        s_pMainWindow->mouseRelease(event);
    } while(false);
    return;
}

static void viewResize(QResizeEvent *event)
{
    do {
        CC_BREAK_IF(s_pMainWindow == NULL);
        s_pMainWindow->resize(event->size().width(), event->size().height());
    } while (false);
    return;
}

GLView::GLView()
    : m_bCaptured(false)
    , m_fFrameZoomFactor(1.0f)
    , m_bSupportTouch(false)
    , m_bIsInit(false)
    , m_window(NULL)
    , m_fScreenScaleFactor(1.0f)
    , m_glParentWidget(NULL)
    , GLViewWindowMode(GLVIEW_WINDOW_MODE_FIXSIZE)
{
    m_pTouch = new Touch;
    m_pSet = new std::vector<Touch*>();
//    m_glParentWidget = new QWidget;
//    m_glParentWidget->setAttribute(Qt::WA_PaintOnScreen);
}

GLView::~GLView()
{
    CC_SAFE_DELETE(m_pTouch);
    CC_SAFE_DELETE(m_pSet);
}

GLView* GLView::getInstance()
{
    return s_pMainWindow;
}

//bool GLView::initGL()
//{
//    return true;
//}

//void GLView::destroyGL()
//{
//}

bool GLView::_createInWidget(QWidget* parent)
{
    bool bRet = false;
    do {
        CC_BREAK_IF(m_window);
        Q_ASSERT(parent);

        m_glParentWidget = parent;
//        // Qt Window
//        float iWidth = m_glParentWidget->frameGeometry().size().width();     // m_glParentWidget->frameSize().width();
//        float iHeight = m_glParentWidget->frameGeometry().size().height();    // m_glParentWidget->frameSize().height();

//        m_window = new GLWidget(param, iWidth, iHeight);
        //m_window = new GLWidget(m_glParentWidget);
        m_window = new GLWidget;
        m_window->setMouseMoveFunc(&cocos2d::mouseMove);
        m_window->setMousePressFunc(&cocos2d::mousePress);
        m_window->setMouseReleaseFunc(&cocos2d::mouseRelease);
//        m_window->setResizeFunc(&cocos2d::viewResize);
//        m_window->makeCurrent();

//        QLayout* layout = param->layout();
//        if( ! layout)
//        {
            QVBoxLayout* _newBoxLayout = new QVBoxLayout;
            _newBoxLayout->setMargin(0);
            _newBoxLayout->setSpacing(0);
            _newBoxLayout->addWidget(m_window);
            m_glParentWidget->setLayout(_newBoxLayout);
//        }

//        bRet = initGL();
//        if(!bRet) destroyGL();
//        CC_BREAK_IF(!bRet);

        m_bIsInit = true;
        s_pMainWindow = this;
        bRet = true;

    } while (0);
    return bRet;
}

bool GLView::isOpenGLReady()
{
    return m_bIsInit;
}

void GLView::end()
{
    CC_SAFE_DELETE(m_pSet);
    CC_SAFE_DELETE(m_pTouch);
//    CC_SAFE_DELETE(m_glParentWidget);
    CC_SAFE_DELETE(m_window);

    s_pMainWindow = NULL;
    delete this;
}

void GLView::swapBuffers()
{
    if (m_bIsInit)
    {
        /* Swap buffers */
//        m_window->makeCurrent();
        m_window->swapBuffers();
    }
}


void GLView::setIMEKeyboardState(bool /*bOpen*/)
{

}

void GLView::setViewName(const std::string &pszViewName)
{
    GLViewProtocol::setViewName(pszViewName);
    if (m_glParentWidget) {
        m_glParentWidget->setWindowTitle(getViewName().c_str());
    }
}

void GLView::resize(int width, int height)
{
    do {
        CC_BREAK_IF(!m_window);
        CC_BREAK_IF (Director::getInstance()->getOpenGLView() == NULL);

        if (GLViewWindowMode == GLVIEW_WINDOW_MODE_FIXSIZE) {
            m_window->setFixedSize(width, height);
            m_glParentWidget->setFixedSize(width, height);
        }
        else {
            setDesignResolutionSize(width, height, ResolutionPolicy::EXACT_FIT);
        }

    } while(false);
    return;
}

void GLView::setFrameZoomFactor(float fZoomFactor)
{
//    CCTRACE();
    m_fFrameZoomFactor = fZoomFactor;
    resize(_screenSize.width * fZoomFactor, _screenSize.height * fZoomFactor);
    centerWindow();
    Director::getInstance()->setProjection(Director::getInstance()->getProjection());
}

float GLView::getFrameZoomFactor()
{
    return m_fFrameZoomFactor;
}

void GLView::setFrameSize(float width, float height)
{
//    CCTRACE();
    GLViewProtocol::setFrameSize(width, height);

    resize(width, height); // adjust window size for menubar
    centerWindow();
}

void GLView::centerWindow()
{
//    CCTRACE();
//    if (m_glParentWidget && !m_glParentWidget->parent()) {
//        QDesktopWidget *w = qApp->desktop();
//        QRect rect = w->screenGeometry();
//        m_glParentWidget->move((rect.width()-m_glParentWidget->width())/2.0f
//                              ,(rect.height()-m_glParentWidget->height())/2.0f);
//    }
}

//void GLView::moveWindow(int left, int top)
//{
//    if (m_glParentWidget && !m_glParentWidget->parent()) {
//        m_glParentWidget->move(left, top);
//    }
//}

void GLView::setViewPortInPoints(float x , float y , float w , float h)
{
//    CCTRACE();
    GLViewProtocol::setViewPortInPoints(x, y, w, h);
//    glViewport((GLint)(x * _scaleX * m_fFrameZoomFactor + _viewPortRect.origin.x * m_fFrameZoomFactor),
//        (GLint)(y * _scaleY  * m_fFrameZoomFactor + _viewPortRect.origin.y * m_fFrameZoomFactor),
//        (GLsizei)(w * _scaleX * m_fFrameZoomFactor),
//        (GLsizei)(h * _scaleY * m_fFrameZoomFactor));
}

void GLView::setScissorInPoints(float x , float y , float w , float h)
{
//    CCTRACE();
    GLViewProtocol::setScissorInPoints(x, y, w, h);
//    glScissor((GLint)(x * _scaleX * m_fFrameZoomFactor + _viewPortRect.origin.x * m_fFrameZoomFactor),
//              (GLint)(y * _scaleY * m_fFrameZoomFactor + _viewPortRect.origin.y * m_fFrameZoomFactor),
//              (GLsizei)(w * _scaleX * m_fFrameZoomFactor),
//              (GLsizei)(h * _scaleY * m_fFrameZoomFactor));
}

GLView* GLView::create(const std::string &viewName)
{
    GLView* view = GLView::create(NULL);
    view->setViewName(viewName);
    return view;
}

GLView* GLView::create(QWidget* parent)
{
    return GLView::createWithWidget(parent);
}

GLView* GLView::createWithWidget(QWidget* parent)
{
    do {
        CC_BREAK_IF(s_pMainWindow);         /// if have already created GLView before, just returns.

        s_pMainWindow = new GLView;
        if(!s_pMainWindow->_createInWidget(parent)) {
            CC_SAFE_DELETE(s_pMainWindow);
        }

    } while (false);
    return s_pMainWindow;
}

GLView* GLView::createWithRect(const std::string &viewName, Rect rect, float frameZoomFactor)
{
    return NULL;
}

GLView* GLView::createWithFullScreen(const std::string &viewName)
{
    return NULL;
}

void GLView::mouseMove(QMouseEvent *event)
{
    if (/*! m_pDelegate || */! m_pTouch)
        return;

    if (! m_bCaptured)
        return;

    m_pTouch->setTouchInfo(0, (float)(event->x()) / m_fScreenScaleFactor, (float)(event->y()) / m_fScreenScaleFactor);

    intptr_t id = m_pTouch->getID();
    float x = m_pTouch->getLocationInView().x;
    float y = m_pTouch->getLocationInView().y;
    this->handleTouchesMove(1, &id, &x, &y);

    return;
}

void GLView::mousePress(QMouseEvent *event)
{
    if (/*! m_pDelegate ||*/ ! m_pTouch)
        return;

    if (event->button() != Qt::LeftButton)
        return;

    m_bCaptured = true;

    m_pTouch->setTouchInfo(0, (float)(event->x()) / m_fScreenScaleFactor,
        (float)(event->y()) / m_fScreenScaleFactor);
    m_pSet->push_back(m_pTouch);

    intptr_t id = m_pTouch->getID();
    float x = m_pTouch->getLocationInView().x;
    float y = m_pTouch->getLocationInView().y;
    this->handleTouchesBegin(1, &id, &x, &y);

    return;
}

void GLView::mouseRelease(QMouseEvent *event)
{
    if (/*! m_pDelegate || */! m_pTouch)
        return;

    if (event->button() != Qt::LeftButton)
        return;

    m_bCaptured = false;

    m_pTouch->setTouchInfo(0, (float)(event->x()) / m_fScreenScaleFactor,
        (float)(event->y()) / m_fScreenScaleFactor);

    intptr_t id = m_pTouch->getID();
    float x = m_pTouch->getLocationInView().x;
    float y = m_pTouch->getLocationInView().y;
    this->handleTouchesEnd(1, &id, &x, &y);

    /// remove the touch info from m_pSet
    for( std::vector<Touch*>::iterator iteEachTouch = m_pSet->begin();
         iteEachTouch != m_pSet->end();
         ++iteEachTouch)
    {
        if (*iteEachTouch == m_pTouch) {
            m_pSet->erase(iteEachTouch);
            break;
        }
    }

    return;
}

void GLView::setAccelerometerKeyHook(ACCEL_PTRFUN func)
{
    if (m_window)
        m_window->setKeyEventFunc(func);
}

QWidget *GLView::getGLWidget(void)
{
//    return m_glParentWidget;
    return m_window;
}

void GLView::updateGL()
{
//    CCLOG("GLView::updateGL");
    if (m_window)
        m_window->updateGL();
}

NS_CC_END
