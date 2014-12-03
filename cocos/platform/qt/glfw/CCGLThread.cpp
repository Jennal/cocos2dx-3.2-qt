#include "CCGLThread.h"
#include "base/CCDirector.h"

static long getCurrentMillSecond() {
    long lLastTime;
    struct timeval stCurrentTime;

    gettimeofday(&stCurrentTime,NULL);
    lLastTime = stCurrentTime.tv_sec*1000+stCurrentTime.tv_usec*0.001; //millseconds
    return lLastTime;
}

NS_CC_BEGIN

GLThread::GLThread()
    : QThread(),
      _animationInterval(1.0f/60.0f*1000.0f)
{

}

GLThread::~GLThread()
{
    QThread::~QThread();
}

void GLThread::run()
{
    CCLOG("GLThread::run: ThreadId: %p", QThread::currentThread());

    long lastTime = 0L;
    long curTime = 0L;

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    // Retain glview to avoid glview being released in the while loop
    glview->retain();

    while (!glview->windowShouldClose())
    {
        lastTime = getCurrentMillSecond();

        glview->makeCurrent();

        director->mainLoop();
//        glview->pollEvents();

        glview->doneCurrent();

        curTime = getCurrentMillSecond();
        if (curTime - lastTime < _animationInterval)
        {
            usleep((_animationInterval - curTime + lastTime)*1000);
        }
    }
    /* Only work on Desktop
    *  Director::mainLoop is really one frame logic
    *  when we want to close the window, we should call Director::end();
    *  then call Director::mainLoop to do release of internal resources
    */
    if (glview->isOpenGLReady())
    {
        director->end();
        director->mainLoop();
        director = nullptr;
    }
    glview->release();
}

NS_CC_END
