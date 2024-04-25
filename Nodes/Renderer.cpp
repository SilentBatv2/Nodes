#include "stdafx.h"
#include "Renderer.h"

Renderer::Renderer(QWidget* parent)
{
    

}

Renderer::~Renderer()
{
}

void Renderer::initializeGL()
{
	initializeOpenGLFunctions();

    writer = new Writer("res/arial.fnt", "res/arial.png");

	writer->write(10, 12, "maybe");
}

void Renderer::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);

	screenSize = { w, h };
}

void Renderer::paintGL()
{
	glClearColor(0.25f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	writer->paint();
}

void Renderer::mousePressEvent(QMouseEvent* event)
{
}

void Renderer::mouseMoveEvent(QMouseEvent* event)
{
}

void Renderer::mouseReleaseEvent(QMouseEvent* event)
{
}
