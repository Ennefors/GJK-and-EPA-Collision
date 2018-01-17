#pragma once
#include "core/app.h"
#include <map>
#include "tdMathLibNew.h"

class ShaderObject
{
private:
	GLuint program = 0;
	GLuint vertexShader;
	GLuint fragmentShader;

	std::map<string, GLuint> uniMap;
public:

	ShaderObject() {};
	~ShaderObject();

	void loadVertexShader(char*);
	void loadFragmentShader(char*);
	void loadProgram();
	void apply();

	void getUniLoc(string);

	void setUniMat(string, fdMatrix);
	void setUniInt(string name, int i);
	void setUniVec(string, fdVector);

	GLuint getProgram() { return program; }
};