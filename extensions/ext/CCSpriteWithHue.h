//
//  CCSpriteWithHue.h
//  HelloWorld
//
//  Copyright (c) 2013 Alexey Naumov. All rights reserved.
//  Ported by Jacky on 15/5/8.
//
//

#ifndef __CCSpriteWithHue_H__
#define __CCSpriteWithHue_H__

#include "cocos2d.h"
#include "../ExtensionMacros.h"
NS_CC_EXT_BEGIN


class SpriteWithHue: public cocos2d::Sprite
{
public:
    static SpriteWithHue* create(const std::string& filename);
    static SpriteWithHue* create(const std::string& filename, const cocos2d::Rect& rect);
    
    static SpriteWithHue* createWithTexture(cocos2d::Texture2D *texture);
    static SpriteWithHue* createWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect& rect, bool rotated=false);
    
    static SpriteWithHue* createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame);
    static SpriteWithHue* createWithSpriteFrameName(const std::string& spriteFrameName);
    
    float getHue();
    void setHue(float hue);
    
protected:
    float _hue;
    GLfloat _mat[3][3];
    
    bool initWithTexture(cocos2d::Texture2D *texture);
    bool initWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect& rect);
    virtual bool initWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect, bool rotated);
    virtual bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame);
    
    void setupDefaultSettings();
    void initShader();
    const GLchar* shaderBody();
    virtual void updateColor();
    void updateColorMatrix();
    void updateAlpha();
    GLfloat getAlpha();
    
    void hueUniformCallback(cocos2d::GLProgram *p, cocos2d::Uniform *u);
};
NS_CC_EXT_END

#endif /* defined(__CCSpriteWithHue_H__) */
