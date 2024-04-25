#pragma once
#include <QOpenglWidget>
#include "Writer.h"

class Renderer :
    public QOpenGLWidget, protected QOpenGLExtraFunctions
{
private:
    
    QPoint screenSize;
    unsigned int shaderProgram;
    Writer* writer;
public:
    Renderer(QWidget* parent = nullptr);

    ~Renderer();
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
};

