set(APP_NAME cpp-empty-test)

if(ENV_QT)
  include(proj.qt/CMakeLists.txt)
elseif(ANDROID)
  set(PLATFORM_SRC
    proj.android/jni/hellocpp/main.cpp
  )
elseif(WIN32)
  set(PLATFORM_SRC
    proj.win32/main.cpp
  )
elseif(APPLE)
  if(IOS)
    set(PLATFORM_SRC
      proj.ios/main.m
	  proj.ios/AppController.mm
	  proj.ios/RootViewController.mm
    )
  else()
    set(PLATFORM_SRC
      proj.mac/main.cpp
    )
  endif()
else()
  set(PLATFORM_SRC
    proj.linux/main.cpp
  )
  endif()

set(SAMPLE_SRC
  Classes/AppDelegate.cpp
  Classes/HelloWorldScene.cpp
  ${PLATFORM_SRC}
)

# add the executable
add_executable(${APP_NAME}
  MACOSX_BUNDLE
  WIN32
  ${SAMPLE_SRC}
)

if(ENV_QT)
  target_link_libraries(${APP_NAME} Qt5::Core)
  target_link_libraries(${APP_NAME} Qt5::Widgets)
  target_link_libraries(${APP_NAME} Qt5::Gui)
  target_link_libraries(${APP_NAME} Qt5::OpenGL)
endif(ENV_QT)

if(APPLE)
  target_link_libraries(${APP_NAME} ${LINK_LIB_APPLE})
endif(APPLE)

if(WIN32 AND MSVC)
  #get our resources
  add_custom_command(TARGET ${APP_NAME} PRE_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_directory
                         ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${CMAKE_CURRENT_BINARY_DIR})
  #get our dlls
  add_custom_command(TARGET ${APP_NAME} PRE_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy
                     ${CMAKE_CURRENT_SOURCE_DIR}/../../../external/win32-specific/gles/prebuilt/glew32.dll 
					 ${CMAKE_CURRENT_BINARY_DIR})

  add_custom_command(TARGET ${APP_NAME} PRE_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy
                     ${CMAKE_CURRENT_SOURCE_DIR}/../../../external/win32-specific/zlib/prebuilt/zlib1.dll 
					 ${CMAKE_CURRENT_BINARY_DIR}/Debug)

  #Visual Studio Defaults to wrong type
  set_target_properties(${APP_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")
  set_target_properties(${APP_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
else()
  set(APP_BIN_DIR "${CMAKE_BINARY_DIR}/bin")
  message("APP_BIN_DIR: " ${APP_BIN_DIR})

  set_target_properties(${APP_NAME} PROPERTIES
       RUNTIME_OUTPUT_DIRECTORY  "${APP_BIN_DIR}")

if(APPLE)
  pre_build(${APP_NAME}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}/${APP_NAME}.app/Contents/Resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/${APP_NAME}.app/Contents/Resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/${APP_NAME}.app/Contents/Resources
    COMMAND ${CMAKE_COMMAND} -E make_directory ${APP_BIN_DIR}/${APP_NAME}.app/Contents/MacOS
  )
else()
  pre_build(${APP_NAME}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}/Resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/Resources
  )
endif(APPLE)

endif()

if(BUILD_AUDIO)
  set (AUDIO_LIB audio)
endif(BUILD_AUDIO)

target_link_libraries(${APP_NAME}
  ${AUDIO_LIB}
  cocos2d
)

