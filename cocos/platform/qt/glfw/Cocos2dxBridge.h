#ifndef COCOS2DXBRIDGE_H
#define COCOS2DXBRIDGE_H

#include <string>
#include "cocos2d.h"

class Cocos2dxBridge : public cocos2d::Ref
{
public:
    virtual ~Cocos2dxBridge(){}

    static Cocos2dxBridge* getInstance();
    void cocos2dxEvent(int id, std::string params);

public:
    enum ActionID{
        UPDATE_MAP_SIZE = 1
    };

protected:
    Cocos2dxBridge();
};

#endif // COCOS2DXBRIDGE_H
