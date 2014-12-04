#QT5_ADD_RESOURCES(
#    QT_RES_FILES res/xxx.qrc
#)

QT5_WRAP_UI(QT_UI_FILES
  proj.qt/ui/MainWindow.ui
)

qt5_wrap_cpp(QT_MOC_FILES
  proj.qt/src/MainWindow.h
  proj.qt/src/TabPageWidget.h
)

set(PLATFORM_SRC
  ${QT_UI_FILES}
  ${QT_MOC_FILES}
  ${QT_RES_FILES}
  proj.qt/src/MainWindow.cpp
  proj.qt/src/TabPageWidget.cpp
  proj.qt/main.cpp
)

include_directories(
  proj.qt
  proj.qt/src
  Classes
)

