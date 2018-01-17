#include "core/app.h"
#include "render/window.h"


class TextureResource {
private:
	GLuint texture;
	GLuint textureID;
public:

	void generateTexture();
	void setUp(char*, GLuint);
	void setUp2(char*, int, int);
	unsigned char* getImg(char*);
};