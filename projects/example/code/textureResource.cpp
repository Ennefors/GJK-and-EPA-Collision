#define STB_IMAGE_IMPLEMENTATION
#include "config.h"
#include "textureResource.h"
#include "stb_image.h"

void TextureResource::generateTexture()
{
	glUniform1i(this->textureID, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture);

}

void TextureResource::setUp(char* textureF, GLuint prog)
{
	glLinkProgram(prog);

	glUseProgram(prog);
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture);

	glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	this->textureID = glGetUniformLocation(prog, "diffTex");
    glUniform1i(this->textureID, 0);

	int x, y, n;

	unsigned char *data = stbi_load(textureF, &x, &y, &n, 4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glGenerateMipmap(GL_TEXTURE_2D);
	glGenerateTextureMipmap(this->texture);


}


void TextureResource::setUp2(char *text, int x, int y)
{
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, text);
	glBindTexture(GL_TEXTURE_2D, 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glGenerateMipmap(GL_TEXTURE_2D);
	glGenerateTextureMipmap(texture);
}



unsigned char * TextureResource::getImg(char* textureF)
{
	int x, y, n;

	unsigned char *data = stbi_load(textureF, &x, &y, &n, 3);

	return data;
}