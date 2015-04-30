#ifndef _CCB_CCCONTROLBUTTONBMFONTLOADER_H_
#define _CCB_CCCONTROLBUTTONBMFONTLOADER_H_

#include "CCControlButtonLoader.h"
#include "extensions//GUI/CCControlExtension/CCControlButton.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class ControlButtonBMFontLoader : public ControlButtonLoader {
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~ControlButtonBMFontLoader() {};
        /**
         * @js NA
         * @lua NA
         */
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControlButtonBMFontLoader, loader);

    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::extension::ControlButton);

        virtual void onHandlePropTypeFntFile(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char* pFntFile, CCBReader * ccbReader);
        virtual void onPropParseBegin(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader);
        virtual void onPropParseEnd(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader);
};

}

#endif
