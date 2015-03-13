//
//  RepeatNode.cpp
//  RDTower
//
//  Created by changshuai on 15/3/11.
//
//

#include "RepeatNode.h"

// #define HERE

//using namespace here

//define static/const params here

NS_CC_EXT_BEGIN

RepeatNode::RepeatNode(void)
:_texture(nullptr),
_repeatMode(RepeatEnum::RepeatNone),
_needUpdate(false)
{
}


RepeatNode::~RepeatNode(void)
{
    if (this->_texture) {
        this->_texture->release();
        this->_texture = nullptr;
    }
}

void RepeatNode::setContentSize(const cocos2d::Size &size)
{
    if(size.equals(this->getContentSize()))
    {
        return;
    }
    Node::setContentSize(size);
    _needUpdate = true;
}

void RepeatNode::setRepeatMode(RepeatEnum repeatMode)
{
    if (_repeatMode == repeatMode) {
        return;
    }
    _repeatMode = repeatMode;
    _needUpdate = true;
}

void RepeatNode::updateRepeatNode()
{
    this->removeAllChildrenWithCleanup(true);
    float scaleX = 1.0;
    float scaleY = 1.0;
    int repeatTimes = 1;
    Size size = this->getContentSize();
    
    switch (_repeatMode) {
        case RepeatHorizon:
        {
            scaleY = size.height / _rect.size.height;
            repeatTimes = floor(size.width / _rect.size.width) + 1;
            scaleX= size.width/(_rect.size.width * repeatTimes);
            break;
        }
        case RepeatVertical:
        {
            scaleX = size.width / _rect.size.width;
            repeatTimes = floor(size.height / _rect.size.height) + 1;
            scaleY = size.height/(_rect.size.height * repeatTimes);
            break;
        }
        default:
            scaleY = size.height / _rect.size.height;
            scaleX = size.width / _rect.size.width;
            break;
    }
    
    Vec2 p = Vec2(0, 0);
    for (int index = 0; index < repeatTimes; index++) {
        //设置偏移量
        if(index > 0){
            if (_repeatMode == RepeatHorizon){
                p.x = _rect.size.width * scaleX + p.x;
            }else if(_repeatMode == RepeatVertical){
                p.y = _rect.size.height * scaleY + p.y;
            }
        }
        this->addSprite(scaleX, scaleY, p);
    }
}

void RepeatNode::addSprite(float scaleX, float scaleY, const cocos2d::Vec2 &position)
{
    Sprite* sprite = Sprite::createWithTexture(_texture, _rect);
    this->addChild(sprite);
    sprite->setScaleX(scaleX);
    sprite->setScaleY(scaleY);
    sprite->setAnchorPoint(Vec2::ZERO);
    sprite->setPosition(position);
}

bool RepeatNode::init(RepeatEnum repeatMode, cocos2d::Texture2D * texture, const cocos2d::Rect &rect, bool rotated /* = false */)
{
    CCASSERT(texture,"texture is null");
    this->setCascadeColorEnabled(true);
    this->setCascadeOpacityEnabled(true);
    this->_texture = texture;
    this->_texture->retain();
    this->_rect = rect;
    this->setRepeatMode(repeatMode);
    this->setContentSize(rect.size);
    return true;
}

void RepeatNode::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags)
{
    if(this->_needUpdate)
    {
        this->updateRepeatNode();
        this->_needUpdate = false;
    }
    Node::visit(renderer, parentTransform, parentFlags);
}

NS_CC_EXT_END