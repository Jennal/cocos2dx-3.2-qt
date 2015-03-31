//
//  Json.cpp
//  RDTower
//
//  Created by zhengle on 15-3-30.
//
//

#include "lua_json.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include <vector>
#include <map>
#include <cmath>

// #define HERE

//using namespace here

//define static/const params here
bool fill_json(lua_State* L, rapidjson::Value* jsonVal, rapidjson::Document* doc);

bool is_int(lua_Number n)
{
    if (floor(n) != n) return false;
    return true;
}

bool is_array_key(lua_Number key, lua_Number lastKey)
{
    if ( ! is_int(key)) return false;
    if ( (key - lastKey) == 1.0) return true;
    
    return false;
}

bool fill_json_node(lua_State* L, int idx, int type, rapidjson::Value* value, rapidjson::Document* doc)
{
    switch (type) {
        case LUA_TNIL:
        {
            //                printf(" nil\n");
            value->SetNull();
            return true;
        }
            break;
        case LUA_TNUMBER:
        {
            auto number = lua_tonumber(L, idx);
            //                printf(" %lf\n", number);
            value->SetDouble(number);
            return true;
        }
            break;
        case LUA_TBOOLEAN:
        {
            auto number = lua_toboolean(L, idx);
            //                printf(" %s\n", number ? "true" : "false");
            value->SetBool(!! number);
            return true;
        }
            break;
        case LUA_TSTRING:
        {
            auto number = lua_tostring(L, idx);
            //                printf(" %s\n", number);
            value->SetString(number, doc->GetAllocator());
            return true;
        }
            break;
        case LUA_TTABLE:
        {
            fill_json(L, value, doc);
            return true;
        }
            break;
        case LUA_TFUNCTION:
        case LUA_TUSERDATA:
        case LUA_TTHREAD:
        case LUA_TLIGHTUSERDATA:
        default:
            break;
    }
    
    return false;
}

bool fill_json(lua_State* L, rapidjson::Value* jsonVal, rapidjson::Document* doc)
{
    int type = lua_type(L, -1);
    if(type != LUA_TTABLE)
    {
        return false;
    }
    
    std::vector<std::pair<rapidjson::Value*, rapidjson::Value*>> list;
    bool isArray = true;
    lua_Number lastKey = 0;
    
    /* table is in the stack at index 't' */
    lua_pushnil(L);  /* first key */
    while (lua_next(L, -2) != 0) {
        std::pair<rapidjson::Value*, rapidjson::Value*> item;
        /* uses 'key' (at index -2) and 'value' (at index -1) */
        int keyType = lua_type(L, -2);
        int valType = lua_type(L, -1);
        
        //handle key
        switch (keyType) {
            case LUA_TNUMBER:
            {
                rapidjson::Value* key = new rapidjson::Value;
                fill_json_node(L, -2, keyType, key, doc);
//                printf("%g => ", number);
                auto number = key->GetDouble();
                if (isArray && (! is_array_key(number, lastKey))) {
                    isArray = false;
                }
                item.first = key;
                lastKey = number;
            }
                break;
            case LUA_TSTRING:
            {
                isArray = false;
//                printf("%s => ", number);
                rapidjson::Value* key = new rapidjson::Value;
                fill_json_node(L, -2, keyType, key, doc);
                item.first = key;
            }
                break;
            case LUA_TNIL:
                /* can't happen! */
            case LUA_TBOOLEAN:
            case LUA_TTABLE:
            case LUA_TFUNCTION:
            case LUA_TUSERDATA:
            case LUA_TTHREAD:
            case LUA_TLIGHTUSERDATA:
            default:
                item.first = nullptr;
                break;
        }
        
        //handle value
        rapidjson::Value* value = new rapidjson::Value;
        if (fill_json_node(L, -1, valType, value, doc))
        {
            item.second = value;
        }else{
            item.second = nullptr;
        }
        
        /* removes 'value'; keeps 'key' for next iteration */
        lua_pop(L, 1);
        list.push_back(item);
    }
    
    if (isArray) {
        jsonVal->SetArray();
    }else{
        jsonVal->SetObject();
    }
    
    for (auto item : list) {
        if (! item.first or ! item.second) {
            if (item.first) delete item.first;
            if (item.second) delete item.second;
            continue;
        }
        
        if (isArray) {
            jsonVal->PushBack(*item.second, doc->GetAllocator());
        }else{
            if ( ! item.first->IsString())
            {
                lua_Number val = item.first->GetDouble();
                
                char buf[32];
                memset(buf, 0, sizeof(buf));
                sprintf(buf, "%g", val);

                item.first->SetString(buf, doc->GetAllocator());
            }
            
            jsonVal->AddMember(*item.first, *item.second, doc->GetAllocator());
        }
        delete item.first;
        delete item.second;
    }
    
    return true;
}

int lua_json_encode(lua_State* L)
{
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if( ! tolua_istable(L, -1, 0, &tolua_err)){
        tolua_error(L,"#ferror in function 'lua_json_encode'.",&tolua_err);
        return 0;
    }
#endif

    //Loop lua table
    rapidjson::Document doc;
    if(fill_json(L, &doc, &doc))
    {
        rapidjson::StringBuffer strBuff;
        rapidjson::Writer<rapidjson::StringBuffer> writer(strBuff);
        doc.Accept(writer);
        lua_pushstring(L, strBuff.GetString());
    }else{
        /* 不是table，全部返回 null */
        lua_pushstring(L, "null");
    }
//    printf("%s\n", strBuff.GetString());
    return 1;
}

void fill_lua(lua_State* L, const rapidjson::Value* value)
{
    if (value->IsArray())
    {
        int count = value->Size();
        lua_createtable(L, count, 0);
        int i = 1;
        for (rapidjson::Value::ConstValueIterator iter = value->Begin(); iter != value->End(); ++iter) {
            fill_lua(L, iter);
            lua_rawseti(L, -2, i);
            ++i;
        }
    }
    else if (value->IsObject())
    {
        int count = value->MemberCount();
        lua_createtable(L, 0, count);
        for (rapidjson::Value::ConstMemberIterator iter = value->MemberBegin(); iter != value->MemberEnd(); ++iter) {
            fill_lua(L, &iter->name);
            fill_lua(L, &iter->value);
            lua_rawset(L, -3);
        }
    }
    else if (value->IsNull())
    {
        lua_pushnil(L);
    }
    else if (value->IsNumber())
    {
        lua_pushnumber(L, value->GetDouble());
    }
    else if (value->IsBool())
    {
        lua_pushboolean(L, value->GetBool());
    }
    else if (value->IsString())
    {
        lua_pushstring(L, value->GetString());
    }
    else
    {
        // unkown type
        lua_pushnil(L);
    }
}

int lua_json_decode(lua_State* L)
{
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if( ! tolua_isstring(L, -1, 0, &tolua_err)){
        tolua_error(L,"#ferror in function 'lua_json_decode'.",&tolua_err);
        return 0;
    }
#endif
    
    //Loop json object
    const char* json = lua_tostring(L, -1);
    rapidjson::Document doc;
    doc.Parse<0>(json);
    if(doc.HasParseError())
    {
        return 0;
    }
    
    fill_lua(L, &doc);
    return 1;
}

int lua_register_json(lua_State* tolua_S)
{
    tolua_function(tolua_S,"encode", lua_json_encode);
    tolua_function(tolua_S,"decode", lua_json_decode);
    return 1;
}

TOLUA_API int register_all_json(lua_State* tolua_S)
{
    tolua_open(tolua_S);
    
    tolua_module(tolua_S,"json",0);
    tolua_beginmodule(tolua_S,"json");
    
    lua_register_json(tolua_S);
    
    tolua_endmodule(tolua_S);
    return 1;
}
