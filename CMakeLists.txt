#/****************************************************************************
# Copyright (c) 2013 cocos2d-x.org
# Copyright (c) 2012-2013 martell malone
# 
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

cmake_minimum_required(VERSION 2.8.11)
project (Cocos2dx)

# The version number
set(Cocos2dxSamples_VERSION_MAJOR 3)
set(Cocos2dxSamples_VERSION_MINOR 0)

include(build/BuildHelpers.CMakeLists.txt)

if(WIN32 OR APPLE)

option(USE_CHIPMUNK "Use chipmunk for physics library" ON)
option(USE_BOX2D "Use box2d for physics library" OFF)
option(DEBUG_MODE "Debug or release?" ON)
option(BUILD_LIBS_LUA "Build lua libraries" ON)
option(BUILD_EXTENSIONS "Build extension library" ON)
option(BUILD_EDITOR_SPINE "Build editor support for spine" OFF)
option(BUILD_EDITOR_COCOSTUDIO "Build editor support for cocostudio" ON)
option(BUILD_EDITOR_COCOSBUILDER "Build editor support for cocosbuilder" ON)
option(BUILD_AUDIO "Build audio" OFF)
option(ENV_QT "Qt environment" ON)

option(BUILD_CppEmptyTest "Only build EmptyCpp sample" ON)
option(BUILD_CppTests "Only build TestCpp sample" OFF)
option(BUILD_LuaTests "Only build TestLua sample" OFF)

else()#temp

option(USE_CHIPMUNK "Use chipmunk for physics library" ON)
option(USE_BOX2D "Use box2d for physics library" OFF)
option(DEBUG_MODE "Debug or release?" ON)
option(BUILD_LIBS_LUA "Build lua libraries" ON)
option(BUILD_EXTENSIONS "Build extension library" ON)
option(BUILD_EDITOR_SPINE "Build editor support for spine" ON)
option(BUILD_EDITOR_COCOSTUDIO "Build editor support for cocostudio" ON)
option(BUILD_EDITOR_COCOSBUILDER "Build editor support for cocosbuilder" ON)
option(BUILD_AUDIO "Build audio" ON)
option(ENV_QT "Qt environment" OFF)

option(BUILD_CppEmptyTest "Only build EmptyCpp sample" ON)
option(BUILD_CppTests "Only build TestCpp sample" ON)
option(BUILD_LuaTests "Only build TestLua sample" ON)
endif()#temp

if(ENV_QT)
  # Find includes in corresponding build directories
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
  # Instruct CMake to run moc automatically when needed.
  # set(CMAKE_AUTOMOC ON)

  # try glfw
  set(USE_GLFW ON)
  add_definitions( -DUSE_GLFW )

  add_definitions( -DCC_TARGET_QT5 -DUSE_FILE32API -DGLEW_STATIC )

  set(QT5_DIR "/Users/jennal/Qt5.4.0/5.4")
  set(QT5_INCLUDE_DIR "${QT5_DIR}/Src/qtbase/include")
  set(QT5_CMAKE_DIR "${QT5_DIR}/clang_64/lib/cmake")
#  set(Qt5Core_DIR "${QT5_CMAKE_DIR}/Qt5Core")
#  set(Qt5Widgets_DIR "${QT5_CMAKE_DIR}/Qt5Widgets")
#  set(Qt5Gui_DIR "${QT5_CMAKE_DIR}/Qt5Gui")

  set(CMAKE_PREFIX_PATH ${QT5_CMAKE_DIR})

  INCLUDE_DIRECTORIES(${QT5_INCLUDE_DIR})

  find_package(Qt5Core)
  find_package(Qt5Widgets)
  find_package(Qt5Gui)
  find_package(Qt5OpenGL)

  set(LINK_LIB_QT
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    Qt5::OpenGL
  )

  # Add the include directories for the Qt 5 Widgets module to
  # the compile lines.
  include_directories(${Qt5Core_INCLUDE_DIRS})
  include_directories(${Qt5Widgets_INCLUDE_DIRS})
  include_directories(${Qt5Gui_INCLUDE_DIRS})
  include_directories(${Qt5OpenGL_INCLUDE_DIRS})

  # Use the compile definitions defined in the Qt 5 Widgets module
  add_definitions(${Qt5Core_DEFINITIONS})
  add_definitions(${Qt5Widgets_DEFINITIONS})
  add_definitions(${Qt5Gui_DEFINITIONS})
  add_definitions(${Qt5OpenGL_DEFINITIONS})

  # Add compiler flags for building executables (-fPIE)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Core_EXECUTABLE_COMPILE_FLAGS}")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Gui_EXECUTABLE_COMPILE_FLAGS}")

endif(ENV_QT)

if(NOT BUILD_AUDIO)
  add_definitions(-DNO_AUDIO)
endif()

if(DEBUG_MODE)
  set(CMAKE_BUILD_TYPE DEBUG)
else(DEBUG_MODE)
  set(CMAKE_BUILD_TYPE RELEASE)
endif(DEBUG_MODE)

set(CMAKE_C_FLAGS_DEBUG "-DCOCOS2D_DEBUG=1")
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})

if(WIN32)
  ADD_DEFINITIONS (-D_USRDLL -DCOCOS2DXWIN32_EXPORTS -D_WINDOWS -DWIN32)

  if(MSVC)
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS 
					-D_SCL_SECURE_NO_WARNINGS 
					-wd4251 -wd4244 -wd4334 
					-wd4005 -wd4820 -wd4710
					-wd4514 -wd4056 -wd4996 -wd4099)
  else(MSVC)#MINGW
  
  endif(MSVC)
elseif(APPLE)


else()#Linux
  ADD_DEFINITIONS(-DLINUX)
endif()


if(NOT MSVC)# all gcc
set(CMAKE_C_FLAGS_DEBUG "-g -Wall -DCOCOS2D_DEBUG=1")
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-std=c99")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x")
endif()

message("CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

if(MINGW)
  add_definitions(-DGLEW_STATIC)
  add_definitions(-D__SSIZE_T)
  set(CMAKE_C_STANDARD_LIBRARIES "${CMAKE_C_STANDARD_LIBRARIES} -lws2_32")
  set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -lws2_32")
endif()


if(USE_CHIPMUNK)
  message("Using chipmunk ...")
  add_definitions(-DCC_ENABLE_CHIPMUNK_INTEGRATION=1)
elseif(USE_BOX2D)
  message("Using box2d ...")
  add_definitions(-DCC_ENABLE_BOX2D_INTEGRATION=1)
else(USE_CHIPMUNK)
  message(FATAL_ERROR "Must choose a physics library.")
endif(USE_CHIPMUNK)

# architecture
if ( CMAKE_SIZEOF_VOID_P EQUAL 8 )
set(ARCH_DIR "64-bit")
else()
set(ARCH_DIR "32-bit")
endif()

if(WIN32) # Win32
  set(PLATFORM_FOLDER win32)
elseif(APPLE)# osx or ios
  set(PLATFORM_FOLDER mac)
else() # Assume Linux
  set(PLATFORM_FOLDER linux)
endif()

if(ENV_QT)
  set(COCOS_PLATFORM_FOLDER qt)
else()
  set(COCOS_PLATFORM_FOLDER ${PLATFORM_FOLDER})
endif(ENV_QT)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/cocos
  ${CMAKE_CURRENT_SOURCE_DIR}/cocos/platform/desktop
  ${CMAKE_CURRENT_SOURCE_DIR}/cocos/platform/${COCOS_PLATFORM_FOLDER}
  ${CMAKE_CURRENT_SOURCE_DIR}/cocos/scripting/lua-bindings/auto
  ${CMAKE_CURRENT_SOURCE_DIR}/cocos/scripting/lua-bindings/manual
  ${CMAKE_CURRENT_SOURCE_DIR}/extensions
  ${CMAKE_CURRENT_SOURCE_DIR}/external
  ${CMAKE_CURRENT_SOURCE_DIR}/external/tinyxml2
  ${CMAKE_CURRENT_SOURCE_DIR}/external/unzip
  ${CMAKE_CURRENT_SOURCE_DIR}/external/edtaa3func
  ${CMAKE_CURRENT_SOURCE_DIR}/external/chipmunk/include/chipmunk
  ${CMAKE_CURRENT_SOURCE_DIR}/external/jpeg/include/${PLATFORM_FOLDER}
  ${CMAKE_CURRENT_SOURCE_DIR}/external/png/include/${PLATFORM_FOLDER}
  ${CMAKE_CURRENT_SOURCE_DIR}/external/tiff/include/${PLATFORM_FOLDER}
  ${CMAKE_CURRENT_SOURCE_DIR}/external/webp/include/${PLATFORM_FOLDER}
  ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw3/include/${PLATFORM_FOLDER}
  ${CMAKE_CURRENT_SOURCE_DIR}/external/freetype2/include/${PLATFORM_FOLDER}
  ${CMAKE_CURRENT_SOURCE_DIR}/external/websockets/include/${PLATFORM_FOLDER}
  ${CMAKE_CURRENT_SOURCE_DIR}/external/xxhash
  ${CMAKE_CURRENT_SOURCE_DIR}/external/xxtea
)
if(BUILD_AUDIO)
  include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/cocos/audio/include
  )
endif(BUILD_AUDIO)

if(WIN32 AND NOT MINGW)
  include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/external/${PLATFORM_FOLDER}-specific/gles/include/OGLES
    ${CMAKE_CURRENT_SOURCE_DIR}/external/${PLATFORM_FOLDER}-specific/icon/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/${PLATFORM_FOLDER}-specific/zlib/include
    external/curl/include/${PLATFORM_FOLDER}
  )
elseif(APPLE)
  include_directories(
  	${CMAKE_CURRENT_SOURCE_DIR}/external/curl/include/${PLATFORM_FOLDER}
  )
else()
  include_directories(
    /usr/include
    /usr/include/GLFW
    /usr/local/include/GLFW
    ${CMAKE_CURRENT_SOURCE_DIR}/external/${PLATFORM_FOLDER}-specific/fmod/include/${ARCH_DIR}
  )
endif()


if(WIN32)

  if(NOT MINGW)
  link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/external/jpeg/prebuilt/${PLATFORM_FOLDER}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/tiff/prebuilt/${PLATFORM_FOLDER}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/png/prebuilt/${PLATFORM_FOLDER}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/freetype2/prebuilt/${PLATFORM_FOLDER}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/curl/prebuilt/${PLATFORM_FOLDER}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/${PLATFORM_FOLDER}-specific/icon/prebuilt
    ${CMAKE_CURRENT_SOURCE_DIR}/external/${PLATFORM_FOLDER}-specific/zlib/prebuilt
  )
  endif()

elseif(APPLE)

  # if(USE_GLFW)
  #   include_directories(
  #     /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/
  #   )
  # endif(USE_FLFW)

  link_directories(
    /usr/local/lib
    /usr/lib
  )

  find_library(LIB_COCOA Cocoa)
  find_library(LIB_FOUNDATION Foundation)
  find_library(LIB_OPENGL OpenGL)
  find_library(LIB_AGL AGL)
  # find_library(LIB_TK Tk)

  message("LIB_COCOA: " ${LIB_COCOA})
  message("LIB_FOUNDATION: " ${LIB_FOUNDATION})
  message("LIB_OPENGL: " ${LIB_OPENGL})
  message("LIB_AGL: " ${LIB_AGL})
  # message("LIB_TK: " ${LIB_TK})

  set(LINK_LIB_APPLE
    ${LIB_COCOA}
    ${LIB_FOUNDATION}
    ${LIB_OPENGL}
    ${LIB_AGL}
    # ${LIB_TK}
  )

else()

  link_directories(
    /usr/local/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/external/jpeg/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/tiff/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/webp/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/png/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/freetype2/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/websockets/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/${PLATFORM_FOLDER}-specific/fmod/prebuilt/${ARCH_DIR}
  )

endif()

# chipmunk library
add_subdirectory(external/chipmunk/src)

# box2d library
add_subdirectory(external/Box2D)

# unzip library
add_subdirectory(external/unzip)

# tinyxml2 library
add_subdirectory(external/tinyxml2)

# xxhash library
add_subdirectory(external/xxhash)

# audio
if(BUILD_AUDIO)
  add_subdirectory(cocos/audio)
endif(BUILD_AUDIO)

# cocos2d library
add_subdirectory(cocos)

if(BUILD_EXTENSIONS)
# extensions
add_subdirectory(extensions)
endif(BUILD_EXTENSIONS)

## Editor Support

if(BUILD_EDITOR_SPINE)
# spine
add_subdirectory(cocos/editor-support/spine)
else()
add_definitions(-DNO_SPINE)
endif(BUILD_EDITOR_SPINE)

if(BUILD_EDITOR_COCOSBUILDER)
# cocosbuilder
add_subdirectory(cocos/editor-support/cocosbuilder)
endif(BUILD_EDITOR_COCOSBUILDER)

if(BUILD_EDITOR_COCOSTUDIO)
# cocostudio
add_subdirectory(cocos/editor-support/cocostudio)
endif(BUILD_EDITOR_COCOSTUDIO)

## Scripting
if(BUILD_LIBS_LUA)
# lua
add_subdirectory(external/lua/lua)

# tolua
add_subdirectory(external/lua/tolua)

# luabinding
add_subdirectory(cocos/scripting/lua-bindings)

# xxtea
add_subdirectory(external/xxtea)
endif(BUILD_LIBS_LUA)

# build tests 

if(BUILD_CppEmptyTest)
add_subdirectory(tests/cpp-empty-test)
endif(BUILD_CppEmptyTest)

if(BUILD_CppTests)
add_subdirectory(tests/cpp-tests)
endif(BUILD_CppTests)

if(BUILD_LuaTests)
add_subdirectory(tests/lua-tests/project)
add_subdirectory(tests/lua-empty-test/project)
endif(BUILD_LuaTests)
