#include "TabPageWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>

TabPageWidget::TabPageWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;
    QScrollArea* scrollArea = new QScrollArea;

    layout->setMargin(0);
    layout->addWidget(scrollArea);

    QVBoxLayout* scrollLayout = new QVBoxLayout;
    for(int i=0; i!=2; ++i)
    {
        scrollLayout->addWidget(new QLabel("1"));
        scrollLayout->addWidget(new QLabel("2"));
        scrollLayout->addWidget(new QLabel("3"));
        scrollLayout->addWidget(new QLabel("4"));
        scrollLayout->addWidget(new QLabel("5"));
    }
    scrollLayout->addStretch();
    //TODO: generate contents here

    QWidget* contentWidget = new QWidget;
    contentWidget->setLayout(scrollLayout);
    scrollArea->setWidget(contentWidget);

    this->setLayout(layout);
}

TabPageWidget::~TabPageWidget()
{

}

