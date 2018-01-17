
#include "GraphicsNode.h"
#include <assert.h>

void GraphicsNode::draw()
{
	assert(!(shader == nullptr || mesh == nullptr || texture == nullptr));
	this->shader->apply();

	this->texture->generateTexture();

	this->shader->setUniMat("rotation", transformation);
	this->mesh->draw();
}

void GraphicsNode::setupShaders(char* fs, char* vs)
{
	this->shader->loadFragmentShader(fs);
	this->shader->loadVertexShader(vs);
	this->shader->loadProgram();
}