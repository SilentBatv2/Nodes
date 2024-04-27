#include "stdafx.h"
#include "Renderer.h"

Renderer::Renderer(QWidget* parent)
{
    

}

Renderer::~Renderer()
{
}

void DebugCallback (unsigned int source, unsigned int type,
	unsigned int id, unsigned int severity,
	int length, const char* message, const void* userParam)
{
	std::string errormessage = std::to_string(source) + ", " + std::to_string(type) + ", " + std::to_string(severity) + message;
	QMessageBox::critical((QWidget*)userParam, "OpenGL Error", errormessage.c_str());
}

void Renderer::initializeGL()
{
	initializeOpenGLFunctions();

	glDebugMessageCallback(DebugCallback, this);

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
