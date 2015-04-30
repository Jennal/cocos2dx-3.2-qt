//
//  TTFConfigLoader.cpp
//  cocos2d_libs
//
//  Created by zhengle on 15-4-22.
//
//

#include "TTFConfigLoader.h"

// #define HERE

//using namespace here

//define static/const params here

namespace cocosbuilder {

TTFConfigLoader::TTFConfigLoader(void)
{
}


TTFConfigLoader::~TTFConfigLoader(void)
{
}

Config* TTFConfigLoader::getConfig(cocos2d::Node* node)
{
    auto iter = configMap.find(node);
    if (iter != configMap.end()) return &(iter->second);
    
    configMap[node] = Config();
    return &(configMap[node]);
}

void TTFConfigLoader::delConfig(cocos2d::Node* node)
{
    auto iter = configMap.find(node);
    if (iter == configMap.end()) return;
    
    configMap.erase(iter);
}

}