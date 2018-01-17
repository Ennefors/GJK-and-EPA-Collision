//------------------------------------------------------------------------------
/**
	Application class used for example application.
	
	(C) 2015 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "GraphicsNode.h"
#include "LightObject.h"
#include "tdMathLibNew.h"
#include "Raycast.h"
#include <GL/glut.h>
#include <chrono>

namespace Example
{
class ExampleApp : public Core::App
{
public:
	GLuint matrixPos;
	GraphicsNode graphics;
	GraphicsNode graphics2;
	GraphicsNode graphics3;
	GraphicsNode graphics4;
	GraphicsNode graphics5;

	GraphicsNode lines;
	vector<GraphicsNode> gnodes;

	LightObject light;
	LightObject light2;
	LightObject light3;
	LightObject light4;
	LightObject light5;

	fdMatrix mov;
	fdMatrix rot;
	fdMatrix projectionMatrix;
	fdMatrix viewMatrix;

    GLFWcursor* hCursor;

	fdVector xAxis;
	fdVector yAxis;
	fdVector zAxis;

	fdVector lHit;

	fdVector eye;
	fdVector target = fdVector(0,0,0);
	fdVector up = fdVector(0, 1, 0);

	Raycast ray;
	int xAcc = 0;
	int yAcc = 0;

	float xAccM = 0;
	float yAccM = 0;

	double dt = 0.01;

	int keysPressedx = 0;
	int keysPressedy = 0;
	/// constructor
	ExampleApp();
	/// destructor
	~ExampleApp();

	/// open app
	bool Open();
	/// run app
	void Run();
private:
	GLuint program;
	GLuint vertexShader;
	GLuint pixelShader;
	GLuint triangle;
	Display::Window* window;
};
} // namespace Example