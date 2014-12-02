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

#include "base/CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_QT5

#include "platform/CCDevice.h"
#include "base/ccTypes.h"
#include "platform/CCImage.h"
#include <QtGui/QImage>
#include <QtGui/QFontDatabase>
#include <QtGui/QPainter>

NS_CC_BEGIN

class BitmapDC
{
public:
    BitmapDC() : m_pPainter(NULL)
      , m_pImage(NULL)
    {
    }

    ~BitmapDC()
    {
        CC_SAFE_DELETE(m_pPainter);
        CC_SAFE_DELETE(m_pImage);
    }

    bool drawText(const char * pszText, QSize& size, const FontDefinition &textDefinition, const char * pFontName = NULL, int fontSize = 0)
    {
        bool nRet = false;
        do
        {
            CC_BREAK_IF(pszText == NULL || strlen(pszText) <= 0);

            // Set font
            std::string fontName = pFontName;

            if (fontName.c_str())
            {
                int nFindttf = fontName.find(".ttf");
                int nFindTTF = fontName.find(".TTF");
                if (nFindttf >= 0 || nFindTTF >= 0)
                {
                    QFontDatabase::addApplicationFont(fontName.c_str());

                    // delete .ttf suffix from fontName
                    int nFindPos = fontName.rfind("/");
                    fontName = &fontName[nFindPos+1];
                    nFindPos = fontName.rfind(".");
                    fontName = fontName.substr(0, nFindPos);
                }
            }

            int flags = 0;
            if (textDefinition._alignment == TextHAlignment::CENTER) {
                flags |= Qt::AlignHCenter;
            }
            else if (textDefinition._alignment == TextHAlignment::LEFT) {
                flags |= Qt::AlignLeft;
            }
            else if (textDefinition._alignment == TextHAlignment::RIGHT) {
                flags |= Qt::AlignRight;
            }

            if (textDefinition._vertAlignment == TextVAlignment::TOP) {
                flags |= Qt::AlignTop;
            }
            else if (textDefinition._vertAlignment == TextVAlignment::BOTTOM) {
                flags |= Qt::AlignBottom;
            }
            else if (textDefinition._vertAlignment == TextVAlignment::CENTER) {
                flags |= Qt::AlignVCenter;
            }

            QRect rect;
            QFont font(fontName.c_str(), fontSize);
            QImage* image = new QImage(100, 100, QImage::Format_ARGB32);
            QPainter painter(image);
            painter.setFont(font);
            rect = painter.boundingRect(rect, flags, pszText);

            // if content width is 0, use text size as content size
//            if (size.width() <= 0)
//            {
                size.setWidth(rect.width());
                size.setHeight(rect.height());
//            }

            QRect drawRect(0, 0, 0, 0);
            drawRect.setRight(rect.width());
            drawRect.setBottom(rect.height());

            m_pImage = new QImage(size, QImage::Format_ARGB32);
            m_pPainter = new QPainter(m_pImage);

            m_pPainter->setCompositionMode(QPainter::CompositionMode_Source);
            m_pPainter->fillRect(drawRect, Qt::transparent);
            m_pPainter->setCompositionMode(QPainter::CompositionMode_SourceOver);

            m_pPainter->setPen(Qt::white);
            m_pPainter->setFont(font);
            m_pPainter->drawText(drawRect, flags, pszText);
            m_pPainter->end();

//            CC_SAFE_DELETE(m_pPainter);

            nRet = true;
        } while (0);
        return nRet;
    }
private:
    friend class Device;

    QPainter* m_pPainter;
    QImage* m_pImage;
};

static BitmapDC& sharedBitmapDC(void)
{
    static BitmapDC s_bmpDC;
    return s_bmpDC;
}

int
Device::getDPI()
{
    return 160;
}

void
Device::setAccelerometerInterval(float interval)
{
    CC_UNUSED_PARAM(interval);
    return;
}

void
Device::setAccelerometerEnabled(bool isEnabled)
{
    CC_UNUSED_PARAM(isEnabled);
    return;
}

Data
Device::getTextureDataForText(const char *text, const FontDefinition &textDefinition, TextAlign align, int &width, int &height, bool& hasPremultipliedAlpha)
{
    Data _retData = Data::Null;
    do {
        CC_BREAK_IF(text == NULL);
        BitmapDC& _dc = sharedBitmapDC();

        bool bRet = false;
        QSize size;
        size.setWidth(width);
        size.setHeight(height);
        /// draw the text on the bitmap DC.
        bRet = _dc.drawText(text, size,
                            textDefinition,
                            textDefinition._fontName.c_str(),
                            textDefinition._fontSize);
        CC_BREAK_IF(bRet == false);

        width = size.width();
        height = size.height();

        unsigned long nLen = 0l;
#if (QT_VERSION < QT_VERSION_CHECK(5, 0,0))
            nLen = _dc.m_pImage->numBytes();
#else
            nLen = _dc.m_pImage->byteCount();
#endif  //
        _retData.copy(_dc.m_pImage->bits(), nLen);

        //TODO: this should set by platform??
        hasPremultipliedAlpha = false;

    } while (false);
    return _retData;
}

NS_CC_END
#endif  /// CC_TARGET_PLATFORM == CC_PLATFORM_QT5

