#ifndef _CCB_CCCONTROLBUTTONLOADER_H_
#define _CCB_CCCONTROLBUTTONLOADER_H_

#include "CCControlLoader.h"
#include "TTFConfigLoader.h"
#include "extensions/GUI/CCControlExtension/CCControlButton.h"
#include "2d/CCLabel.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class ControlButtonLoader : public ControlLoader, public TTFConfigLoader {
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~ControlButtonLoader() {};
        /**
         * @js NA
         * @lua NA
         */
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControlButtonLoader, loader);

    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::extension::ControlButton);

        virtual void onHandlePropTypeScaleLock(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, float * pScaleLock, CCBReader * ccbReader);
        virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader);
        virtual void onHandlePropTypeByte(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader);
        virtual void onHandlePropTypeString(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader);
        virtual void onHandlePropTypeFontTTF(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader);
        virtual void onHandlePropTypeFloatScale(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader);
        virtual void onHandlePropTypePoint(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Vec2 pPoint, CCBReader * ccbReader);
        virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader);
        virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader);
        virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color3B pColor3B, CCBReader * ccbReader);
    
        virtual void onPropParseBegin(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader);
        virtual void onPropParseEnd(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader);

        cocos2d::Label* getLabelForState(cocos2d::Node* pNode, cocos2d::extension::Control::State state);
        void setTitleTTFForState(cocos2d::Node* pNode, const char * pFontTTF, cocos2d::extension::Control::State state);
        void setTitleTTFSizeForState(cocos2d::Node* pNode, float pFloatScale, cocos2d::extension::Control::State state);
};

}

#endif
