#ifndef __CCGLTHREAD_H__
#define __CCGLTHREAD_H__

#include <QtCore/QThread>
#include "CCGLView.h"

NS_CC_BEGIN

class GLThread : public QThread
{
public:
    explicit GLThread();
    virtual ~GLThread();

protected:
    virtual void run();

private:
    long _animationInterval;
};

NS_CC_END

#endif /* __CCGLTHREAD_H__ */
