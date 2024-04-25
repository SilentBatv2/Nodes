#pragma once
#include "stdafx.h"
#include "stb/stb_image.h"

class Texture : protected QOpenGLExtraFunctions
{
	unsigned int m_texid;
	std::string m_filepath;
	unsigned char* m_localbuffer;
	int height, width, BPP;
	unsigned int sampler_slot;
public:
	Texture(std::string path);
	~Texture();

	void bind(unsigned int slot = 0);
	void unbind();

	inline int getheight() { return height; }
	inline int getwidth() { return width; }
	inline int getBPP() { return BPP; }
	inline unsigned int getslot() { return sampler_slot; }
};