//
//  TTFConfigLoader.h
//  cocos2d_libs
//
//  Created by zhengle on 15-4-22.
//
//

#ifndef __cocos2d_libs__TTFConfigLoader__
#define __cocos2d_libs__TTFConfigLoader__

#include "CCNodeLoader.h"
#include <map>
#include <string>

namespace cocosbuilder {

struct Config{
    bool outlineEnabled;
    cocos2d::Color4B outlineColor;
    int outlineSize;
    
    bool shadowEnabled;
    cocos2d::Color4B shadowColor;
    cocos2d::Size shadowOffset;
    int shadowBlur;
    
    int fontSize;
    std::string fontName;
    bool isSystemFont;
    
    
    Config()
    : outlineEnabled(false),
    shadowEnabled(false),
    outlineColor(cocos2d::Color4B::BLACK),
    outlineSize(0),
    shadowOffset(2, -2),
    shadowBlur(0),
    shadowColor(cocos2d::Color4B::BLACK),
    fontSize(12),
    isSystemFont(true)
    {}
};
    
class TTFConfigLoader
{
public:
	TTFConfigLoader(void);
	~TTFConfigLoader(void);
    
    Config* getConfig(cocos2d::Node* node);
    void delConfig(cocos2d::Node* node);
    
protected:
    std::map<cocos2d::Node*, Config> configMap;
};

}

#endif /* defined(__cocos2d_libs__TTFConfigLoader__) */
