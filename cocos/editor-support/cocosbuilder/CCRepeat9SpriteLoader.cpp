#include "CCRepeat9SpriteLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define PROPERTY_CONTENTSIZE "contentSize"
#define PROPERTY_SPRITEFRAME "spriteFrame"
#define PROPERTY_COLOR "color"
#define PROPERTY_OPACITY "opacity"
#define PROPERTY_BLENDFUNC "blendFunc"
#define PROPERTY_PREFEREDSIZE "preferedSize" // TODO Should be "preferredSize". This is a typo in cocos2d-iphone, cocos2d-x and CocosBuilder!
#define PROPERTY_INSETLEFT "insetLeft"
#define PROPERTY_INSETTOP "insetTop"
#define PROPERTY_INSETRIGHT "insetRight"
#define PROPERTY_INSETBOTTOM "insetBottom"
#define PROPERTY_REPEATLEFT "leftRepeat"
#define PROPERTY_REPEATTOP "topRepeat"
#define PROPERTY_REPEATRIGHT "rightRepeat"
#define PROPERTY_REPEATBOTTOM "bottomRepeat"

namespace cocosbuilder {

void Repeat9SpriteLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_SPRITEFRAME) == 0) {
        ((Repeat9Sprite *)pNode)->setSpriteFrame(pSpriteFrame);
    } else {
        NodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void Repeat9SpriteLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_COLOR) == 0) {
        ((Repeat9Sprite *)pNode)->setColor(pColor3B);
    } else {
        NodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
    }
}

void Repeat9SpriteLoader::onHandlePropTypeByte(Node * pNode, Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_OPACITY) == 0) {
        ((Repeat9Sprite *)pNode)->setOpacity(pByte);
    } else {
        NodeLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, ccbReader);
    }
}

void Repeat9SpriteLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        // TODO Not exported by CocosBuilder yet!
        // ((Repeat9Sprite *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        NodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

void Repeat9SpriteLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size pSize, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
        //((Repeat9Sprite *)pNode)->setContentSize(pSize);
    } else if(strcmp(pPropertyName, PROPERTY_PREFEREDSIZE) == 0) {
        ((Repeat9Sprite *)pNode)->setPreferredSize(pSize);
    } else {
        NodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void Repeat9SpriteLoader::onHandlePropTypeFloat(Node * pNode, Node * pParent, const char * pPropertyName, float pFloat, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_INSETLEFT) == 0) {
        ((Repeat9Sprite *)pNode)->setInsetLeft(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETTOP) == 0) {
        ((Repeat9Sprite *)pNode)->setInsetTop(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETRIGHT) == 0) {
        ((Repeat9Sprite *)pNode)->setInsetRight(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETBOTTOM) == 0) {
        ((Repeat9Sprite *)pNode)->setInsetBottom(pFloat);
    } else {
        NodeLoader::onHandlePropTypeFloat(pNode, pParent, pPropertyName, pFloat, ccbReader);
    }
}

void Repeat9SpriteLoader::onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, bool pCheck, CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_REPEATLEFT) == 0) {
        ((Repeat9Sprite *)pNode)->setRepeatModeToEdge(pCheck, Left);
    } else if(strcmp(pPropertyName, PROPERTY_REPEATTOP) == 0) {
        ((Repeat9Sprite *)pNode)->setRepeatModeToEdge(pCheck, Top);
    } else if(strcmp(pPropertyName, PROPERTY_REPEATRIGHT) == 0) {
        ((Repeat9Sprite *)pNode)->setRepeatModeToEdge(pCheck, Right);
    } else if(strcmp(pPropertyName, PROPERTY_REPEATBOTTOM) == 0) {
        ((Repeat9Sprite *)pNode)->setRepeatModeToEdge(pCheck, Bottom);
    } else {
        NodeLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, ccbReader);
    }
}
    
}
