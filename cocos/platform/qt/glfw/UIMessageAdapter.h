#ifndef UIMESSAGEADAPTER_H
#define UIMESSAGEADAPTER_H

#include <QObject>
#include <QMutex>
#include <QQueue>
#include <string>

class UIMessageAdapter : public QObject
{
    Q_OBJECT
public:
    explicit UIMessageAdapter();
    ~UIMessageAdapter();
    static UIMessageAdapter* getInstance();

    void push(const char*);
    const std::string pop(bool &ok);

signals:
    void cocos2dxWindowPosChanged(int x, int y);
    void cocos2dxEventSignals(int id, std::string params);

private:
    QMutex m_mutex;
    QQueue<std::string> m_data;

signals:

public slots:
};

#endif // UIMESSAGEADAPTER_H
