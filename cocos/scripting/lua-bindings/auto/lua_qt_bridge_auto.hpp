#include "base/ccConfig.h"
#ifndef __qt_h__
#define __qt_h__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_qt(lua_State* tolua_S);




#endif // __qt_h__
