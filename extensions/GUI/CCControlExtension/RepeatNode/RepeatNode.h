//
//  RepeatNode.h
//  RDTower
//
//  Created by changshuai on 15/3/11.
//
//

#ifndef __RDTower__RepeatNode__
#define __RDTower__RepeatNode__

#include "cocos2d.h"
#include "../CCControlUtils.h"
#include "RepeatEnum.h"

using namespace cocos2d;

NS_CC_EXT_BEGIN

class RepeatNode : public cocos2d::Node
{
public:
    RepeatNode(void);
    ~RepeatNode(void);
    static RepeatNode* create(RepeatEnum mode, cocos2d::Texture2D* texture, const Rect& tRect, bool rotated = false)
    {
        RepeatNode* rnode = new RepeatNode();
        if (rnode->init(mode,texture, tRect,rotated)) {
            rnode->autorelease();
            return rnode;
        }else{
            delete rnode;
            return nullptr;
        }
    };

    
    bool init(RepeatEnum,Texture2D*, const Rect&, bool rotated );
    void setContentSize(const Size &size);
    void addSprite(float scaleX, float scaleY, const Vec2& position);
    
    void setRepeatMode(RepeatEnum repeatMode);
    inline RepeatEnum getRepeatMode(){ return _repeatMode;};
    void visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags);
private:
    void updateRepeatNode();
    
    Texture2D* _texture;
    Rect _rect;
    RepeatEnum _repeatMode;
    bool _needUpdate;
};

NS_CC_EXT_END

#endif /* defined(__RDTower__RepeatNode__) */
