set(LUABINDING_SRC
  auto/lua_cocos2dx_auto.cpp
  # auto/lua_cocos2dx_controller_auto.cpp
  auto/lua_cocos2dx_experimental_auto.cpp
  # auto/lua_cocos2dx_experimental_video_auto.cpp
  auto/lua_cocos2dx_extension_auto.cpp
  auto/lua_cocos2dx_physics_auto.cpp
  auto/lua_cocos2dx_spine_auto.cpp
  auto/lua_cocos2dx_studio_auto.cpp
  auto/lua_cocos2dx_ui_auto.cpp
  auto/lua_qt_bridge_auto.cpp
  manual/lua_debugger.c
  manual/lua_extensions.c
  manual/CCBProxy.cpp
  manual/CCLuaBridge.cpp
  manual/CCLuaEngine.cpp
  manual/CCLuaStack.cpp
  manual/CCLuaValue.cpp
  manual/Cocos2dxLuaLoader.cpp
  manual/lua_cocos2dx_coco_studio_manual.cpp
  # manual/lua_cocos2dx_controller_manual.cpp
  manual/lua_cocos2dx_deprecated.cpp
  manual/lua_cocos2dx_experimental_manual.cpp
  # manual/lua_cocos2dx_experimental_video_manual.cpp
  manual/lua_cocos2dx_extension_manual.cpp
  manual/lua_cocos2dx_manual.cpp
  manual/lua_cocos2dx_physics_manual.cpp
  manual/lua_cocos2dx_spine_manual.cpp
  manual/lua_cocos2dx_ui_manual.cpp
  manual/Lua_web_socket.cpp
  manual/lua_xml_http_request.cpp
  manual/LuaBasicConversions.cpp
  manual/LuaOpengl.cpp
  manual/LuaScriptHandlerMgr.cpp
  manual/LuaSkeletonAnimation.cpp
  manual/tolua_fix.cpp
)

include_directories(
  auto
  manual
  ../../editor-support
  ../../editor-support/cocosbuilder
  ../../editor-support/cocostudio
  ../../editor-support/spine
  ../../base
  ../../ui
  ../../2d
  ../../3d
  ../../../external/lua
  ../../../external/lua/lua
  ../../../external/lua/tolua
  ../../../external/xxtea
)

if(WIN32)
  include_directories(
    ../../../external/win32-specific/gles/include
  )
endif(WIN32)

add_library(luabinding STATIC
  ${LUABINDING_SRC}
)

if(BUILD_EDITOR_SPINE)
  set(TARGET_SPINE_LIB spine)
endif(BUILD_EDITOR_SPINE)

target_link_libraries(luabinding
  tolua
  lua
  xxtea
  luasocket
  ${TARGET_SPINE_LIB}
  cocos2d
  extensions
  cocosbuilder
  cocostudio
)

set_target_properties(luabinding
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

