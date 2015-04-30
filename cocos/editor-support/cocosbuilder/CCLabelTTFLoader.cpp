#include "CCLabelTTFLoader.h"
#include <map>

using namespace cocos2d;

#define PROPERTY_COLOR "color"
#define PROPERTY_OPACITY "opacity"
#define PROPERTY_BLENDFUNC "blendFunc"
#define PROPERTY_FONTNAME "fontName"
#define PROPERTY_FONTSIZE "fontSize"
#define PROPERTY_HORIZONTALALIGNMENT "horizontalAlignment"
#define PROPERTY_VERTICALALIGNMENT "verticalAlignment"
#define PROPERTY_STRING "string"
#define PROPERTY_DIMENSIONS "dimensions"

#define PROPERTY_OUTLINE_ENABLED "outlineEnabled"
#define PROPERTY_OUTLINE_SIZE "outlineSize"
#define PROPERTY_OUTLINE_COLOR "outlineColor"
#define PROPERTY_SHADOW_ENABLED "shadowEnabled"
#define PROPERTY_SHADOW_COLOR "shadowColor"
#define PROPERTY_SHADOW_OFFSET "shadowOffset"
#define PROPERTY_SHADOW_BLUR "shadowBlur"

#define PROPERTY_IS_SYSTEM_FONT "isSystemFont"

namespace cocosbuilder {
    
void LabelTTFLoader::onHandlePropTypeCheck(cocos2d::Node *pNode, cocos2d::Node *pParent, const char *pPropertyName, bool pCheck, cocosbuilder::CCBReader *ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_OUTLINE_ENABLED) == 0) {
        auto config = getConfig(pNode);
        config->outlineEnabled = pCheck;
    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_ENABLED) == 0) {
        auto config = getConfig(pNode);
        config->shadowEnabled = pCheck;
    } else if (strcmp(pPropertyName, PROPERTY_IS_SYSTEM_FONT) == 0) {
        auto config = getConfig(pNode);
        config->isSystemFont = pCheck;
    } else {
        NodeLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, ccbReader);
    }
}
    
void LabelTTFLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
    /* 保留PROPERTY_COLOR、PROPERTY_OUTLINE_COLOR、PROPERTY_SHADOW_COLOR 确保旧的ccbi的兼容性 */
    if(strcmp(pPropertyName, PROPERTY_COLOR) == 0) {
        Color4B color(pColor3B.r, pColor3B.g, pColor3B.b, 255);
        ((Label *)pNode)->setTextColor(color);
    } else if (strcmp(pPropertyName, PROPERTY_OUTLINE_COLOR) == 0) {
        auto config = getConfig(pNode);
        Color4B color(pColor3B.r, pColor3B.g, pColor3B.b, 255);
        config->outlineColor = color;
    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_COLOR) == 0) {
        auto config = getConfig(pNode);
        Color4B color(pColor3B.r, pColor3B.g, pColor3B.b, 255);
        config->shadowColor = color;
    } else {
        NodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
    }
}

//void LabelTTFLoader::onHandlePropTypeColor4FVar(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, cocos2d::Color4F * pColor4FVar, CCBReader * ccbReader)
//{
//    if(strcmp(pPropertyName, PROPERTY_COLOR) == 0) {
//        Color4B color(pColor4FVar->r, pColor4FVar->g, pColor4FVar->b, pColor4FVar->a);
//        ((Label *)pNode)->setTextColor(color);
//    } else if (strcmp(pPropertyName, PROPERTY_OUTLINE_COLOR) == 0) {
//        auto config = getConfig(pNode);
//        Color4B color(pColor4FVar->r, pColor4FVar->g, pColor4FVar->b, pColor4FVar->a);
//        config->outlineColor = color;
//    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_COLOR) == 0) {
//        auto config = getConfig(pNode);
//        Color4B color(pColor4FVar->r, pColor4FVar->g, pColor4FVar->b, pColor4FVar->a);
//        config->shadowColor = color;
//    } else {
//        NodeLoader::onHandlePropTypeColor4FVar(pNode, pParent, pPropertyName, pColor4FVar, ccbReader);
//    }
//}
    
void LabelTTFLoader::onHandlePropTypeByte(Node * pNode, Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_OPACITY) == 0) {
        ((Label *)pNode)->setOpacity(pByte);
    } else if(strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
        auto config = getConfig(pNode);
        config->fontSize = (int)pByte;
    } else if (strcmp(pPropertyName, PROPERTY_OUTLINE_SIZE) == 0) {
        auto config = getConfig(pNode);
        config->outlineSize = (int)pByte;
    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_BLUR) == 0) {
        auto config = getConfig(pNode);
        config->shadowBlur = (int)pByte;
    } else {
        NodeLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        ((Label *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        NodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeFontTTF(Node * pNode, Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_FONTNAME) == 0) {
        auto config = getConfig(pNode);
        config->fontName = pFontTTF;
    } else {
        NodeLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeText(Node * pNode, Node * pParent, const char * pPropertyName, const char * pText, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_STRING) == 0) {
        ((Label *)pNode)->setString(pText);
    } else {
        NodeLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, pText, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader) {
    /* 保留FONTSIZE 确保旧的ccbi的兼容性 */
    if(strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
        auto config = getConfig(pNode);
        config->fontSize = (int)pFloatScale;
    } else {
        NodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeIntegerLabeled(Node * pNode, Node * pParent, const char * pPropertyName, int pIntegerLabeled, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_HORIZONTALALIGNMENT) == 0) {
        ((Label *)pNode)->setHorizontalAlignment(TextHAlignment(pIntegerLabeled));
    } else if(strcmp(pPropertyName, PROPERTY_VERTICALALIGNMENT) == 0) {
        ((Label *)pNode)->setVerticalAlignment(TextVAlignment(pIntegerLabeled));
    } else {
        NodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pIntegerLabeled, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size size, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_DIMENSIONS) == 0) {
        ((Label *)pNode)->setDimensions(size.width,size.height);
    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_OFFSET) == 0) {
        auto config = getConfig(pNode);
        config->shadowOffset = size;
    } else {
        NodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, size, ccbReader);
    }
}

void LabelTTFLoader::onPropParseBegin(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader)
{
    
}
    
void LabelTTFLoader::onPropParseEnd(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader)
{
    Label* label = ((Label *)pNode);
    auto config = getConfig(pNode);
    
    if (config->isSystemFont) {
        label->setSystemFontName(config->fontName);
        label->setSystemFontSize(config->fontSize);
    }else{
        auto ttfConfig = label->getTTFConfig();
        ttfConfig.fontFilePath = config->fontName;
        ttfConfig.fontSize = config->fontSize;
        label->setTTFConfig(ttfConfig);
    }
    
    if (config->outlineEnabled) {
        label->enableOutline(config->outlineColor, config->outlineSize);
    }
    
    if (config->shadowEnabled) {
        label->enableShadow(config->shadowColor, config->shadowOffset, config->shadowBlur);
    }
    
    delConfig(pNode);
}
    
}
