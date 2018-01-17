#pragma once
#include <memory>
#include "ShaderObject.h"
#include "MeshResource.h"
#include "textureResource.h"

class GraphicsNode
{
private:
	std::shared_ptr<ShaderObject> shader;
	std::shared_ptr<MeshResource> mesh;
	std::shared_ptr<TextureResource> texture;
	



public:
	fdMatrix transformation;
	bool struck = false;

	void setMat(fdMatrix mat)
	{
		transformation = mat;
	}

	fdMatrix getMat()
	{
		return transformation;
	}

	void setShader(std::shared_ptr<ShaderObject> s)
	{
		shader = s;
	};
	void setMesh(std::shared_ptr<MeshResource> m)
	{
		mesh = m;
	};
	void setTexture(std::shared_ptr<TextureResource> t)
	{
		texture = t;
	};

	std::shared_ptr<ShaderObject> getShader() { return shader; };
	std::shared_ptr<MeshResource> getMesh() { return mesh; };
	std::shared_ptr<TextureResource> getTexture() { return texture; };

	void setupShaders(char*, char*);
	void draw();
};