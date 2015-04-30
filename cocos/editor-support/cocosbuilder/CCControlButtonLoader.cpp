#include "CCControlButtonLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

namespace cocosbuilder {;

#define PROPERTY_ZOOMONTOUCHDOWN "zoomOnTouchDown"
#define PROPERTY_TITLE_NORMAL "title|1"
#define PROPERTY_TITLE_HIGHLIGHTED "title|2"
#define PROPERTY_TITLE_DISABLED "title|3"
#define PROPERTY_TITLECOLOR_NORMAL "titleColor|1"
#define PROPERTY_TITLECOLOR_HIGHLIGHTED "titleColor|2"
#define PROPERTY_TITLECOLOR_DISABLED "titleColor|3"
#define PROPERTY_TITLETTF_NORMAL "titleTTF|1"
#define PROPERTY_TITLETTF_HIGHLIGHTED "titleTTF|2"
#define PROPERTY_TITLETTF_DISABLED "titleTTF|3"
#define PROPERTY_TITLETTFSIZE_NORMAL "titleTTFSize|1"
#define PROPERTY_TITLETTFSIZE_HIGHLIGHTED "titleTTFSize|2"
#define PROPERTY_TITLETTFSIZE_DISABLED "titleTTFSize|3"
#define PROPERTY_LABELANCHORPOINT "labelAnchorPoint"
#define PROPERTY_PREFEREDSIZE "preferedSize" // TODO Should be "preferredSize". This is a typo in cocos2d-iphone, cocos2d-x and CocosBuilder!
#define PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL "backgroundSpriteFrame|1"
#define PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED "backgroundSpriteFrame|2"
#define PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED "backgroundSpriteFrame|3"

#define PROPERTY_OUTLINE_ENABLED "outlineEnabled"
#define PROPERTY_OUTLINE_SIZE "outlineSize"
#define PROPERTY_OUTLINE_COLOR "outlineColor"
#define PROPERTY_SHADOW_ENABLED "shadowEnabled"
#define PROPERTY_SHADOW_COLOR "shadowColor"
#define PROPERTY_SHADOW_OFFSET "shadowOffset"
#define PROPERTY_SHADOW_BLUR "shadowBlur"

#define PROPERTY_IS_SYSTEM_FONT "isSystemFont"
    
    
void ControlButtonLoader::onHandlePropTypeScaleLock(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, float * pScaleLock, CCBReader * ccbReader)
{
    ControlLoader::onHandlePropTypeScaleLock(pNode, pParent, pPropertyName, pScaleLock, ccbReader);
    ((ControlButton *)pNode)->setScaleOriginX(pScaleLock[0]);
    ((ControlButton *)pNode)->setScaleOriginY(pScaleLock[1]);
}
    
void ControlButtonLoader::onHandlePropTypeCheck(Node * pNode, Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_ZOOMONTOUCHDOWN) == 0) {
        ((ControlButton *)pNode)->setZoomOnTouchDown(pCheck);
    } else if(strcmp(pPropertyName, PROPERTY_OUTLINE_ENABLED) == 0) {
        auto config = getConfig(pNode);
        config->outlineEnabled = pCheck;
    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_ENABLED) == 0) {
        auto config = getConfig(pNode);
        config->shadowEnabled = pCheck;
    } else if (strcmp(pPropertyName, PROPERTY_IS_SYSTEM_FONT) == 0) {
        auto config = getConfig(pNode);
        config->isSystemFont = pCheck;
    } else {
        ControlLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeByte(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader)
{
    if (strcmp(pPropertyName, PROPERTY_OUTLINE_SIZE) == 0) {
        auto config = getConfig(pNode);
        config->outlineSize = (int)pByte;
    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_BLUR) == 0) {
        auto config = getConfig(pNode);
        config->shadowBlur = (int)pByte;
    } else {
        ControlLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, ccbReader);
    }
}
    
void ControlButtonLoader::onHandlePropTypeString(Node * pNode, Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLE_NORMAL) == 0) {
        ((ControlButton *)pNode)->setTitleForState(pString, Control::State::NORMAL);
    } else if(strcmp(pPropertyName, PROPERTY_TITLE_HIGHLIGHTED) == 0) {
        ((ControlButton *)pNode)->setTitleForState(pString, Control::State::HIGH_LIGHTED);
    } else if(strcmp(pPropertyName, PROPERTY_TITLE_DISABLED) == 0) {
        ((ControlButton *)pNode)->setTitleForState(pString, Control::State::DISABLED);
    } else {
        ControlLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeFontTTF(Node * pNode, Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLETTF_NORMAL) == 0) {
        auto config = getConfig(pNode);
        config->fontName = pFontTTF;
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTF_HIGHLIGHTED) == 0) {
        auto config = getConfig(pNode);
        config->fontName = pFontTTF;
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTF_DISABLED) == 0) {
        auto config = getConfig(pNode);
        config->fontName = pFontTTF;
    } else {
        ControlLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_NORMAL) == 0) {
        auto config = getConfig(pNode);
        config->fontSize = (int)pFloatScale;
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_HIGHLIGHTED) == 0) {
        auto config = getConfig(pNode);
        config->fontSize = (int)pFloatScale;
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_DISABLED) == 0) {
        auto config = getConfig(pNode);
        config->fontSize = (int)pFloatScale;
    } else {
        ControlLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypePoint(Node * pNode, Node * pParent, const char * pPropertyName, Vec2 pPoint, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_LABELANCHORPOINT) == 0) {
        ((ControlButton *)pNode)->setLabelAnchorPoint(pPoint);
    } else {
        ControlLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size pSize, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_PREFEREDSIZE) == 0) {
        ((ControlButton *)pNode)->setPreferredSize(pSize);
    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_OFFSET) == 0) {
        auto config = getConfig(pNode);
        config->shadowOffset = pSize;
    } else {
        ControlLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL) == 0) {
        if(pSpriteFrame != nullptr) {
            ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::NORMAL);
        }
    } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED) == 0) {
        if(pSpriteFrame != nullptr) {
            ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::HIGH_LIGHTED);
        }
    } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED) == 0) {
        if(pSpriteFrame != nullptr) {
            ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::DISABLED);
        }
    } else {
        ControlLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_NORMAL) == 0) {
        ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::NORMAL);
    } else if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_HIGHLIGHTED) == 0) {
        ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::HIGH_LIGHTED);
    } else if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_DISABLED) == 0) {
        ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::DISABLED);
    } else if (strcmp(pPropertyName, PROPERTY_OUTLINE_COLOR) == 0) {
        auto config = getConfig(pNode);
        Color4B color(pColor3B.r, pColor3B.g, pColor3B.b, 255);
        config->outlineColor = color;
    } else if (strcmp(pPropertyName, PROPERTY_SHADOW_COLOR) == 0) {
        auto config = getConfig(pNode);
        Color4B color(pColor3B.r, pColor3B.g, pColor3B.b, 255);
        config->shadowColor = color;
    } else {
        ControlLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
    }
}

void ControlButtonLoader::onPropParseBegin(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader)
{
    
}

void ControlButtonLoader::onPropParseEnd(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader)
{
    auto controlButton = dynamic_cast<ControlButton*>(pNode);
    if ( ! controlButton) return;
    
    auto config = getConfig(pNode);
    
    cocos2d::extension::Control::State states[] = {
        cocos2d::extension::Control::State::NORMAL,
        cocos2d::extension::Control::State::HIGH_LIGHTED,
        cocos2d::extension::Control::State::DISABLED
    };
    
    for (int i=0; i < 3; ++i) {
        cocos2d::extension::Control::State state = states[i];
        if (config->isSystemFont)
        {
            controlButton->setTitleLabelForState(Label::createWithSystemFont(controlButton->getTitleForState(state), config->fontName, config->fontSize), state);
        }
        else
        {
            this->setTitleTTFForState(pNode, config->fontName.c_str(), state);
            this->setTitleTTFSizeForState(pNode, config->fontSize, state);
        }
        
        auto label = this->getLabelForState(pNode, state);
        if ( ! label) continue;
        
        if (config->outlineEnabled) {
            label->enableOutline(config->outlineColor, config->outlineSize);
        }
        
        if (config->shadowEnabled) {
            label->enableShadow(config->shadowColor, config->shadowOffset, config->shadowBlur);
        }
    }
    
    delConfig(pNode);
}

cocos2d::Label* ControlButtonLoader::getLabelForState(cocos2d::Node* pNode, cocos2d::extension::Control::State state)
{
    auto controlButton = dynamic_cast<ControlButton*>(pNode);
    if ( ! controlButton) return nullptr;

    auto node = controlButton->getTitleLabelForState(state);
    if ( ! node) return nullptr;

    auto label = dynamic_cast<Label*>(node);
    return label;
}

void ControlButtonLoader::setTitleTTFForState(cocos2d::Node* pNode, const char * pFontTTF, cocos2d::extension::Control::State state)
{
    auto controlButton = dynamic_cast<ControlButton*>(pNode);
    if ( ! controlButton) return;

    controlButton->setTitleLabelForState(Label::createWithTTF(controlButton->getTitleForState(state), pFontTTF, 12), state);
}

void ControlButtonLoader::setTitleTTFSizeForState(cocos2d::Node* pNode, float pFloatScale, cocos2d::extension::Control::State state)
{
    auto label = this->getLabelForState(pNode, state);
    if ( ! label) return;

    auto config = label->getTTFConfig();
    config.fontSize = (int)pFloatScale;
    label->setTTFConfig(config);
}
    
};
