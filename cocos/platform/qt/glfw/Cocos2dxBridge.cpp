#include "cocos2dxbridge.h"
#include "platform/qt/glfw/UIMessageAdapter.h"

static Cocos2dxBridge* m_Instance = NULL;

Cocos2dxBridge::Cocos2dxBridge()
{

}

Cocos2dxBridge* Cocos2dxBridge::getInstance()
{
    if (m_Instance == NULL )
    {
        m_Instance = new Cocos2dxBridge;
    }

    return m_Instance;
}

void Cocos2dxBridge::cocos2dxEvent(int id, std::string params)
{
    printf("Cocos2dxBridge::cocos2dxEvent:%d, %s\n",id, params.c_str());
    fflush(stdout);
    emit UIMessageAdapter::getInstance()->cocos2dxEventSignals(id, params);
}

