#pragma once
#include "stdafx.h"
#include "Texture.h"
#include "FontLoader.h"

class Writer : protected QOpenGLExtraFunctions
{
public:
	Writer(std::string fntpath, std::string texpath);
	~Writer();
	void paint();
	void write(int x, int y, std::string text);
private:
	Texture* tex;
	std::unordered_map<int, tex_dat> data;
	unsigned int VAO, VBO, shaderProgram;
	void setShader();
	std::string texturepath;
};

