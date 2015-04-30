#include "CCControlButtonBMFontLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

namespace cocosbuilder {;

#define PROPERTY_TITLEBMFONT_NORMAL "titleBMFont|1"
#define PROPERTY_TITLEBMFONT_HIGHLIGHTED "titleBMFont|2"
#define PROPERTY_TITLEBMFONT_DISABLED "titleBMFont|3"

void ControlButtonBMFontLoader::onHandlePropTypeFntFile(Node * pNode, Node * pParent, const char * pPropertyName, const char* pFntFile, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLEBMFONT_NORMAL) == 0) {
        ((ControlButton *)pNode)->setTitleBMFontForState(pFntFile, Control::State::NORMAL);
    } else if(strcmp(pPropertyName, PROPERTY_TITLEBMFONT_HIGHLIGHTED) == 0) {
        ((ControlButton *)pNode)->setTitleBMFontForState(pFntFile, Control::State::HIGH_LIGHTED);
    } else if(strcmp(pPropertyName, PROPERTY_TITLEBMFONT_DISABLED) == 0) {
        ((ControlButton *)pNode)->setTitleBMFontForState(pFntFile, Control::State::DISABLED);
    } else {
        ControlButtonLoader::onHandlePropTypeFntFile(pNode, pParent, pPropertyName, pFntFile, ccbReader);
    }
}
    
void ControlButtonBMFontLoader::onPropParseBegin(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader)
{
}

void ControlButtonBMFontLoader::onPropParseEnd(cocos2d::Node *pNode, cocos2d::Node *pParent, cocosbuilder::CCBReader *ccbReader)
{
}
    
};
