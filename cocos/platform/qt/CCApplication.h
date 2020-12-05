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

#ifndef __CC_APPLICATION_WIN32_H__
#define __CC_APPLICATION_WIN32_H__

#include "CCStdC.h"
#include "platform/CCCommon.h"
#include "platform/CCApplicationProtocol.h"
#include <string>

#undef CursorShape
#include <QtWidgets/QApplication>

NS_CC_BEGIN

//class CCRect;

class CC_DLL Application : public QApplication, public ApplicationProtocol
{
    Q_OBJECT
public:
    Application(int argc, char *argv[]);
    virtual ~Application();

    /**
    @brief    Run the message loop.
    */
    int run();

    /**
    @brief    Get current applicaiton instance.
    @return Current application instance pointer.
    */
    static Application* getInstance();

    /* override functions */
    virtual void setAnimationInterval(double interval);
    virtual LanguageType getCurrentLanguage();
    virtual const char * getCurrentLanguageCode();
    
    /**
     @brief Get target platform
     */
    virtual Platform getTargetPlatform();

    const std::string& getStartupScriptFilename(void) {
        return m_startupScriptFilename;
    }
    void setStartupScriptFilename(const std::string& startupScriptFile);

public Q_SLOTS:
    void timerUpdate();

protected:
    long long           m_nAnimationInterval;
    std::string         m_startupScriptFilename;

    static Application * sm_pSharedApplication;

private:
    QTimer *m_timer;
    int m_refCount;
};

NS_CC_END

#endif    // __CC_APPLICATION_WIN32_H__
