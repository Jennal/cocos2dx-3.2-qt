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

#include "CCApplication.h"
#include "CCGLView.h"
#include "base/CCDirector.h"
#include <algorithm>
#include "platform/CCFileUtils.h"

#include <QtCore/QTimer>
/**
@brief    This function change the PVRFrame show/hide setting in register.
@param  bEnable If true show the PVRFrame window, otherwise hide.
*/
static void PVRFrameEnableControlWindow(bool bEnable);

NS_CC_BEGIN

// sharedApplication pointer
Application * Application::sm_pSharedApplication = 0;

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv)
    , m_timer(NULL)
    , m_refCount(0)
{
    m_nAnimationInterval = 1.0f / 60.0f * 1000.0f;
    CC_ASSERT(! sm_pSharedApplication);
    sm_pSharedApplication = this;
}

Application::~Application()
{
    CC_ASSERT(this == sm_pSharedApplication);
    sm_pSharedApplication = NULL;
}

int Application::run()
{
    // Initialize instance and cocos2d.
    if (!applicationDidFinishLaunching())
    {
        return 0;
    }

    m_timer = new QTimer(this);
    QObject::connect(m_timer, SIGNAL(timeout()),
                     this, SLOT(timerUpdate()));
    m_timer->start(m_nAnimationInterval);

    return cocos2d::Application::getInstance()->exec();
}

void Application::setAnimationInterval(double interval)
{
    m_nAnimationInterval = interval * 1000.0f;
    if (m_timer)
    {
        m_timer->start(m_nAnimationInterval);
    }
}

//////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////
Application* Application::getInstance()
{
    CC_ASSERT(sm_pSharedApplication);
    return sm_pSharedApplication;
}

LanguageType Application::getCurrentLanguage()
{
    switch (QLocale::system().language())
    {
    case QLocale::Chinese: return LanguageType::CHINESE;
    case QLocale::Japanese:return LanguageType::JAPANESE;
    case QLocale::Korean:  return LanguageType::KOREAN;
    case QLocale::French:  return LanguageType::FRENCH;
    case QLocale::Italian: return LanguageType::ITALIAN;
    case QLocale::German:  return LanguageType::GERMAN;
    case QLocale::Spanish: return LanguageType::SPANISH;
    case QLocale::Russian: return LanguageType::RUSSIAN;
    case QLocale::Polish:   return LanguageType::POLISH;
    case QLocale::Norwegian:    return LanguageType::NORWEGIAN;
    default:               return LanguageType::ENGLISH;
    }
}

const char * Application::getCurrentLanguageCode()
{
    switch(this->getCurrentLanguage())
    {
    case LanguageType::CHINESE: return "zh";
    case LanguageType::JAPANESE: return "jp";
    case LanguageType::KOREAN: return "ko";
    case LanguageType::FRENCH: return "fr";
    case LanguageType::ITALIAN: return "it";
    case LanguageType::GERMAN: return "de";
    case LanguageType::SPANISH: return "es";
    case LanguageType::RUSSIAN: return "ru";
    case LanguageType::POLISH: return "pl";
    case LanguageType::NORWEGIAN: return "nb";
    default: return "en";
    }
}

ApplicationProtocol::Platform Application::getTargetPlatform()
{
    return Platform::OS_MAC;
}

void Application::setStartupScriptFilename(const std::string& startupScriptFile)
{
    m_startupScriptFilename = startupScriptFile;
    int pos;
    while ((pos = m_startupScriptFilename.find_first_of("\\")) != std::string::npos)
    {
        m_startupScriptFilename.replace(pos, 1, "/");
    }
}

void Application::timerUpdate()
{
    // m_refCount is here to prevent calling the mainloop from nested event loops
    if (!m_refCount)
    {
//        Director::getInstance()->mainLoop();
//        Director::getInstance()->getOpenGLView()->updateGL();
        GLView::getInstance()->updateGL();
    }
}

NS_CC_END

