if(ENV_QT)

qt5_wrap_cpp(QT_MOC_FILES
  platform/qt/CCApplication.h
  platform/qt/CCGLWidget.h
)

set(COCOS_PLATFORM_SPECIFIC_SRC
  platform/qt/CCApplication.cpp
  platform/qt/CCCommon.cpp
  platform/qt/CCDevice.cpp
  platform/qt/CCFileUtilsQt.cpp
  platform/qt/CCGLView.cpp
  platform/qt/CCGLWidget.cpp
  ${QT_MOC_FILES}
)

elseif(WIN32)

ADD_DEFINITIONS(-DUNICODE -D_UNICODE)

set(COCOS_PLATFORM_SPECIFIC_SRC
  platform/win32/CCStdC.cpp
  platform/win32/CCFileUtilsWin32.cpp
  platform/win32/CCCommon.cpp
  platform/win32/CCApplication.cpp
  platform/win32/CCDevice.cpp
)

elseif(APPLE)

else()

set(COCOS_PLATFORM_SPECIFIC_SRC
  platform/linux/CCStdC.cpp
  platform/linux/CCFileUtilsLinux.cpp
  platform/linux/CCCommon.cpp
  platform/linux/CCApplication.cpp
  platform/linux/CCDevice.cpp
)

endif()

include_directories(
  ../external/ConvertUTF
)

set(COCOS_PLATFORM_SRC
  platform/CCSAXParser.cpp
  platform/CCThread.cpp
  platform/CCGLViewProtocol.cpp
  platform/CCFileUtils.cpp
  platform/CCImage.cpp
  ../external/edtaa3func/edtaa3func.cpp
  ../external/ConvertUTF/ConvertUTFWrapper.cpp
  ../external/ConvertUTF/ConvertUTF.c
  ${COCOS_PLATFORM_SPECIFIC_SRC}
)

if(NOT ENV_QT)
  set(COCOS_PLATFORM_SRC
    ${COCOS_PLATFORM_SRC}
    platform/desktop/CCGLView.cpp
  )
endif()
