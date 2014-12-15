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

#include "CCFileUtilsQt.h"
#include "platform/CCCommon.h"

// Qt
#include <QtCore/QObject>
#include <QtCore/QDir>
#include <QtWidgets/QApplication>
#include <QtCore/QFileInfo>

#ifdef Q_OS_MAC
#include <execinfo.h>
#include <stdio.h>
#endif

using namespace std;

NS_CC_BEGIN

FileUtils* FileUtils::getInstance()
{
    if (s_sharedFileUtils == NULL) {
        s_sharedFileUtils = new CCFileUtilsQt();
        s_sharedFileUtils->init();
    }
    return s_sharedFileUtils;
}

CCFileUtilsQt::CCFileUtilsQt()
{
}

bool CCFileUtilsQt::init()
{
#ifdef Q_OS_MAC
    void* callstack[128];
    int i, frames = backtrace(callstack, 128);
    char** strs = backtrace_symbols(callstack, frames);
    for (i = 0; i < frames; ++i) {
        printf("[call-stack] %s\n", strs[i]);
    }
    free(strs);
#endif

    QDir _execDir(qApp->applicationDirPath());
    QDir _resourceDir(_execDir);
    _resourceDir.cdUp();
    _resourceDir.cd("Resources");
    QString _path = _resourceDir.absolutePath();
    if (_path.endsWith("/", Qt::CaseInsensitive) == false) {
        _path.append("/");
    }
    _defaultResRootPath = _path.toStdString();

//    CCLOG("_defaultResRootPath = %s", _defaultResRootPath.c_str());

    return FileUtils::init();
}

bool CCFileUtilsQt::isFileExistInternal(const std::string& strFilePath) const
{
    std::string strPath = strFilePath;
    if (!isAbsolutePath(strPath))
    { // Not absolute path, add the default root path at the beginning.
        strPath.insert(0, _defaultResRootPath);
    }
    QFileInfo fileInfo(strPath.c_str());
    return fileInfo.exists();
}

bool CCFileUtilsQt::isAbsolutePath(const std::string& strPath) const
{
    QFileInfo fileInfo(strPath.c_str());
    return fileInfo.isAbsolute();
}

std::string
CCFileUtilsQt::getWritablePath() const
{
    std::string ret(qApp->applicationDirPath().toLocal8Bit().constData());
    return ret;
}

NS_CC_END
