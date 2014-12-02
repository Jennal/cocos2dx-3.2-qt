#include "cocos2d.h"
#include "AppDelegate.h"

#ifndef USE_GLFW
    #include "MainWindow.h"
    #include <QApplication>
    #include <QtOpenGL/QGLWidget>
#endif

int main(int argc, char *argv[])
{
    AppDelegate app(argc, argv);
    return cocos2d::Application::getInstance()->run();

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

//    QApplication app(argc, argv);
//    QGLWidget widget;

//    widget.makeCurrent();
//    widget.show();

//    GLenum err = glewInit();//<<-- glew function
//    printf("glewInit: %d\n", err);
//    GLuint arr;
//    glGenVertexArrays(1, &arr);//<--no linker error (added just for testing, most likely won't gen arrays)

//    return app.exec();
}
