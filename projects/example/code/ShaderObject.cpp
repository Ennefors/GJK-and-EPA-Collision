#include <fstream>
#include <string.h>
#include "ShaderObject.h"


using namespace std;

ShaderObject::~ShaderObject()
{
	if (this->program != NULL && this->fragmentShader != NULL)
	{
		glDetachShader(this->program, this->fragmentShader);
		glDeleteShader(this->fragmentShader);
	}
	if (this->program != NULL && this->vertexShader != NULL)
	{
		glDetachShader(this->program, this->vertexShader);
		glDeleteShader(this->vertexShader);
	}


}

void ShaderObject::loadVertexShader(char* path)
{
	ifstream infile(path);
	string line;
	string vsStr;

	int i = 0;
	while (getline(infile, line))
	{
		line += "\n";

		vsStr += line;
		i++;
	}

	const GLchar * vs = vsStr.c_str();


	GLint length = strlen(vs);

	this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->vertexShader, 1, &vs, &length);
	glCompileShader(this->vertexShader);

	// get error log
	GLint shaderLogSize;
	glGetShaderiv(this->vertexShader, GL_INFO_LOG_LENGTH, &shaderLogSize);
	if (shaderLogSize > 1)
	{
		GLchar* buf = new GLchar[shaderLogSize];
		glGetShaderInfoLog(this->vertexShader, shaderLogSize, NULL, buf);
		printf("[SHADER COMPILE ERROR]: %s", buf);
		delete[] buf;
	}

}

void ShaderObject::loadFragmentShader(char* path)
{
	ifstream infile(path);
	string line;
	string psStr;

	int i = 0;
	while (getline(infile, line))
	{
		line += "\n";

		psStr += line;
		i++;
	}

	const GLchar *ps = psStr.c_str();

	GLint length = strlen(ps);

	// setup fragment shader
	this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	length = strlen(ps);
	glShaderSource(this->fragmentShader, 1, &ps, &length);
	glCompileShader(this->fragmentShader);

	// get error log
	GLint shaderLogSize;
	glGetShaderiv(this->fragmentShader, GL_INFO_LOG_LENGTH, &shaderLogSize);
	if (shaderLogSize > 1)
	{
		GLchar* buf = new GLchar[shaderLogSize];
		glGetShaderInfoLog(this->fragmentShader, shaderLogSize, NULL, buf);
		printf("[SHADER COMPILE ERROR]: %s", buf);
		delete[] buf;
	}
}

void ShaderObject::loadProgram()
{
	GLint shaderLogSize;

	this->program = glCreateProgram();



	glAttachShader(this->program, this->vertexShader);
	glAttachShader(this->program, this->fragmentShader);

	glLinkProgram(this->program);

	glGetProgramiv(this->program, GL_INFO_LOG_LENGTH, &shaderLogSize);
	if (shaderLogSize > 1)
	{
		GLchar* buf = new GLchar[shaderLogSize];
		glGetProgramInfoLog(this->program, shaderLogSize, NULL, buf);
		printf("[PROGRAM LINK ERROR]: %s", buf);
		delete[] buf;
	}
}

void ShaderObject::apply()
{
	glUseProgram(this->program);
}

void ShaderObject::getUniLoc(string name)
{
	auto search = this->uniMap.find(name);

	if (search != this->uniMap.end())
	{
		cerr << "Uniform already exists." << endl;
		return;
	}

	GLuint loc = glGetUniformLocation(this->program, name.c_str());

	this->uniMap.insert(pair<string, GLuint>(name, loc));
}

void ShaderObject::setUniMat(string name, fdMatrix mat)
{
	auto search = this->uniMap.find(name);

	if (search == this->uniMap.end())
	{
		cerr << "Cant find uniform of that name." << endl;
		return;
	}

	glUniformMatrix4fv(search->second, 1, GL_TRUE, mat.retMat());
}

void ShaderObject::setUniInt(string name, int i)
{
    auto search = this->uniMap.find(name);

    if (search == this->uniMap.end())
    {
        cerr << "Cant find uniform of that name." << endl;
        return;
    }

    glUniform1i(search->second, i);
}

void ShaderObject::setUniVec(string name, fdVector vec)
{
	auto search = this->uniMap.find(name);

	if (search == this->uniMap.end())
	{
		cerr << "Cant find uniform of that name." << endl;
		return;
	}

	glUniform4fv(search->second, 1, vec.retVec());
}