#include "uimessageadapter.h"
#include <QMutexLocker>

using namespace std;

static UIMessageAdapter* s_uiMessageAdapter = nullptr;

UIMessageAdapter::UIMessageAdapter() : QObject(nullptr)
{

}

UIMessageAdapter::~UIMessageAdapter()
{

}

UIMessageAdapter* UIMessageAdapter::getInstance()
{
    if(s_uiMessageAdapter == nullptr)
    {
        s_uiMessageAdapter = new UIMessageAdapter;
    }

    return s_uiMessageAdapter;
}

void UIMessageAdapter::push(const char* message)
{
    //lock & auto unlock
    QMutexLocker locker(&m_mutex);
    Q_UNUSED(locker);

    string msg(message);
    m_data.enqueue(msg);
}

const std::string UIMessageAdapter::pop(bool& ok)
{
    ok = false;
    if(m_data.isEmpty()){
        return "";
    }

    //lock & auto unlock
    QMutexLocker locker(&m_mutex);
    Q_UNUSED(locker);

    //double check
    if(m_data.isEmpty()){
        return "";
    }

    ok = true;
    return m_data.dequeue();
}

