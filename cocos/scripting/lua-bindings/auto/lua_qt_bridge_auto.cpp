#include "lua_qt_bridge_auto.hpp"
#include "platform/qt/glfw/Cocos2dxBridge.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_qt_Cocos2dxBridge_cocos2dxEvent(lua_State* tolua_S)
{
    int argc = 0;
    Cocos2dxBridge* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Cocos2dxBridge",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Cocos2dxBridge*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_qt_Cocos2dxBridge_cocos2dxEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->cocos2dxEvent(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cocos2dxEvent",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_qt_Cocos2dxBridge_cocos2dxEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_qt_Cocos2dxBridge_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Cocos2dxBridge",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        Cocos2dxBridge* ret = Cocos2dxBridge::getInstance();
        object_to_luaval<Cocos2dxBridge>(tolua_S, "Cocos2dxBridge",(Cocos2dxBridge*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_qt_Cocos2dxBridge_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_qt_Cocos2dxBridge_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Cocos2dxBridge)");
    return 0;
}

int lua_register_qt_Cocos2dxBridge(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Cocos2dxBridge");
    tolua_cclass(tolua_S,"Cocos2dxBridge","Cocos2dxBridge","",nullptr);

    tolua_beginmodule(tolua_S,"Cocos2dxBridge");
        tolua_function(tolua_S,"cocos2dxEvent",lua_qt_Cocos2dxBridge_cocos2dxEvent);
        tolua_function(tolua_S,"getInstance", lua_qt_Cocos2dxBridge_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Cocos2dxBridge).name();
    g_luaType[typeName] = "Cocos2dxBridge";
    g_typeCast["Cocos2dxBridge"] = "Cocos2dxBridge";
    return 1;
}
TOLUA_API int register_all_qt(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"qt",0);
	tolua_beginmodule(tolua_S,"qt");

	lua_register_qt_Cocos2dxBridge(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

