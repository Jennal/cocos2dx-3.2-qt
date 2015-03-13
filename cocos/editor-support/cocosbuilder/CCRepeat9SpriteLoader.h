#ifndef _CCB_CCREPEAT9SPRITELOADER_H_
#define _CCB_CCREPEAT9SPRITELOADER_H_

#include "CCNodeLoader.h"
#include "extensions/GUI/CCControlExtension/RepeatNode/Repeat9Sprite.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class Repeat9SpriteLoader : public NodeLoader {
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~Repeat9SpriteLoader() {};
    /**
     * @js NA
     * @lua NA
     */
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Repeat9SpriteLoader, loader);

protected:
    /**
     * @js NA
     * @lua NA
     */
    virtual cocos2d::extension::Repeat9Sprite * createNode(cocos2d::Node * pParent, cocosbuilder::CCBReader * ccbReader) {
        cocos2d::extension::Repeat9Sprite* pNode = cocos2d::extension::Repeat9Sprite::create();
        
        pNode->setAnchorPoint(cocos2d::Vec2::ZERO);
        
        return pNode;
    };
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color3B pColor3B, CCBReader * ccbReader);
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeByte(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader);
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeBlendFunc(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::BlendFunc pBlendFunc, CCBReader * ccbReader);
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader);
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader);
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeFloat(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, float pFloat, CCBReader * ccbReader);
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, bool pCheck, CCBReader * ccbReader);
};

}

#endif
