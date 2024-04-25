#include "stdafx.h"
#include "Texture.h"

Texture::Texture(std::string path) : m_filepath(path), m_texid(0), m_localbuffer(nullptr), height(0), width(0), BPP(0)
{
	initializeOpenGLFunctions();

	stbi_set_flip_vertically_on_load(1);
	m_localbuffer = stbi_load(path.c_str(), &width, &height, &BPP, 4);

	glGenTextures(1, &m_texid);
	glBindTexture(GL_TEXTURE_2D, m_texid);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA8, GL_UNSIGNED_BYTE, m_localbuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	
}

Texture::~Texture()
{
	if (m_localbuffer)
	{
		stbi_image_free(m_localbuffer);
	}
	glDeleteTextures(GL_TEXTURE_2D, &m_texid);
}

void Texture::bind(unsigned int slot)
{
	glActiveTexture(GL_TEXTURE0 + slot);

	glBindTexture(GL_TEXTURE_2D, m_texid);

	sampler_slot = slot;
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
