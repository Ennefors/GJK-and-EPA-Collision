//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "exampleapp.h"
#include "PlaneSweep.h"
#include "Collision.h"


#include <cstring>
fdVector r1;
fdVector r2;

bool fpress = false;
bool lpress = false;
float prevxm = 0;
float prevym = 0;
float cxm = 0;
float cym = 0;
bool once;
float pitch = 0;
float yaw = 0;

using namespace Display;
namespace Example
{

//------------------------------------------------------------------------------
/**
*/
ExampleApp::ExampleApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
ExampleApp::~ExampleApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
bool
ExampleApp::Open()
{


	App::Open();
	this->window = new Display::Window;
	hCursor	= glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);
    glfwSetCursor(this->window->getWindow(), hCursor);
    glfwSetInputMode(this->window->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    window->SetKeyPressFunction([this](int32 key, int32 scancode, int32 action, int32 mods)
	{

		if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{

            if (action == GLFW_PRESS)
                keysPressedy++;
            if (yAcc > 0)
                yAcc = -yAcc;

            if (yAcc != 0)
                yAcc -= 10 / -yAcc;
            else
                yAcc -= 10;
		}
		else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			if (action == GLFW_PRESS)
				keysPressedx++;
			if (xAcc > 0)
				xAcc = -xAcc;
			if (xAcc != 0)
				xAcc -= 10 / -xAcc;
			else
				xAcc -= 10;
		}
		else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
            if (action == GLFW_PRESS)
                keysPressedy++;
            if (yAcc < 0)
                yAcc = -yAcc;

            if (yAcc != 0)
                yAcc += 10 / yAcc;
            else
                yAcc += 10;
		}
		else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			if (action == GLFW_PRESS)
				keysPressedx++;
			if (xAcc < 0)
				xAcc = -xAcc;

			if (xAcc != 0)
				xAcc += 10 / xAcc;
			else
				xAcc += 10;
		}
////////////////////////////////////////////////////////////////////////////////////////
		else if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{

			if (action == GLFW_PRESS)
				keysPressedy++;
			if (yAccM > 0)
				yAccM = -yAccM;

			if (yAccM != 0)
				yAccM -= 10 / -yAccM;
			else
				yAccM -= 10;
		}
		else if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			if (action == GLFW_PRESS)
				keysPressedx++;
			if (xAccM > 0)
				xAccM = -xAccM;
			if (xAccM != 0)
				xAccM -= 10 / -xAccM;
			else
				xAccM -= 10;
		}
		else if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			if (action == GLFW_PRESS)
				keysPressedy++;
			if (yAccM < 0)
				yAccM = -yAccM;

			if (yAccM != 0)
				yAccM += 10 / yAccM;
			else
				yAccM += 10;
		}
		else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			if (action == GLFW_PRESS)
				keysPressedx++;
			if (xAccM < 0)
				xAccM = -xAccM;

			if (xAccM != 0)
				xAccM += 10 / xAccM;
			else
				xAccM += 10;
		}

		else if (key == GLFW_KEY_ESCAPE && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			this->window->Close();
		}

		else if (action == GLFW_RELEASE)
		{
			if (key == GLFW_KEY_D || key == GLFW_KEY_A)
				keysPressedx--;
			if (key == GLFW_KEY_S || key == GLFW_KEY_W)
				keysPressedy--;

			if (key == GLFW_KEY_RIGHT || key == GLFW_KEY_LEFT)
				keysPressedx--;
			if (key == GLFW_KEY_DOWN || key == GLFW_KEY_UP)
				keysPressedy--;

			if (keysPressedy == 0)
			{
				yAcc = 0;
				yAccM = 0;
			}
			if (keysPressedx == 0)
			{
				xAcc = 0;
				xAccM = 0;
			}
		}
	});

	window->SetMousePressFunction([this](int32 button, int32 pressed, int32 mod)
	{
		if (pressed && button == GLFW_MOUSE_BUTTON_RIGHT)
		{
            fpress = true;

		}
		if (pressed && button == GLFW_MOUSE_BUTTON_LEFT)
		{
			lpress = true;

		}
		else if(!pressed)
		{
            fpress = false;
			lpress = false;
            once = true;
			cxm = 0;
			cym = 0;
		}

	});



    window->SetMouseMoveFunction([this](float64 xm, float64 ym) {



            int width, height;
            glfwGetWindowSize(window->getWindow(), &width, &height);

            int mid_x = width  >> 1;
            int mid_y = height >> 1;
            float speed_x  = 0.0f;
            float speed_y  = 0.0f;


            if( (xm == mid_x) && (ym == mid_y) ) return;

            glfwSetCursorPos(this->window->getWindow(), (double)mid_x, (double)mid_y);	// Set the mouse cursor in the center of the window

            // Get the direction from the mouse cursor, set a resonable maneuvering speed
            speed_x = (float)( (mid_x - xm) ) / 1000;
            speed_y = (float)( (mid_y - ym) ) / 1000;
            yaw += (speed_x);

            pitch += (speed_y);

     });


	if (this->window->Open())
	{
		auto sh = shared_ptr<ShaderObject>(new ShaderObject);
		auto me = shared_ptr<MeshResource>(MeshResource::loadObj("/home/bill/Downloads/quad.obj"));
		auto te = shared_ptr<TextureResource>(new TextureResource);


		auto sh2 = shared_ptr<ShaderObject>(new ShaderObject);
		auto me2 = shared_ptr<MeshResource>(MeshResource::loadObj("/home/bill/Downloads/quad.obj"));
		auto te2 = shared_ptr<TextureResource>(new TextureResource);

		auto sh3 = shared_ptr<ShaderObject>(new ShaderObject);
		auto me3 = shared_ptr<MeshResource>(MeshResource::loadObj("/home/bill/Downloads/cube (1).obj"));
		auto te3 = shared_ptr<TextureResource>(new TextureResource);

		auto sh4 = shared_ptr<ShaderObject>(new ShaderObject);
		auto me4 = shared_ptr<MeshResource>(MeshResource::loadObj("/home/bill/Downloads/cube.obj"));
		auto te4 = shared_ptr<TextureResource>(new TextureResource);

		auto sh5 = shared_ptr<ShaderObject>(new ShaderObject);
		auto me5 = shared_ptr<MeshResource>(MeshResource::loadObj("/home/bill/Downloads/cube.obj"));
		auto te5 = shared_ptr<TextureResource>(new TextureResource);

		auto li = shared_ptr<ShaderObject>(new ShaderObject);



		graphics.setMesh(me);
		graphics.setShader(sh);
		graphics.setTexture(te);

		graphics.setupShaders("/home/bill/pxlShader.txt", "/home/bill/vrtShader.txt");
		graphics.getShader()->apply();
		graphics.getShader()->getUniLoc("rotation");
		graphics.getShader()->getUniLoc("inv");
		graphics.getShader()->getUniLoc("normalMat");
		graphics.getShader()->getUniLoc("specColor");
		graphics.getShader()->getUniLoc("lightPos");
		graphics.getShader()->getUniLoc("camPos");
		graphics.getShader()->getUniLoc("diffuseColor");

		graphics2.setMesh(me2);
		graphics2.setShader(sh2);
		graphics2.setTexture(te2);

		graphics2.setupShaders("/home/bill/pxlShader.txt", "/home/bill/vrtShader.txt");
		graphics2.getShader()->apply();
		graphics2.getShader()->getUniLoc("rotation");
		graphics2.getShader()->getUniLoc("inv");
		graphics2.getShader()->getUniLoc("normalMat");
		graphics2.getShader()->getUniLoc("specColor");
		graphics2.getShader()->getUniLoc("lightPos");
		graphics2.getShader()->getUniLoc("camPos");
		graphics2.getShader()->getUniLoc("diffuseColor");

		graphics3.setMesh(me3);
		graphics3.setShader(sh3);
		graphics3.setTexture(te3);

		graphics3.setupShaders("/home/bill/pxlShader.txt", "/home/bill/vrtShader.txt");
		graphics3.getShader()->apply();
		graphics3.getShader()->getUniLoc("rotation");
		graphics3.getShader()->getUniLoc("inv");
		graphics3.getShader()->getUniLoc("normalMat");
		graphics3.getShader()->getUniLoc("specColor");
		graphics3.getShader()->getUniLoc("lightPos");
		graphics3.getShader()->getUniLoc("camPos");
		graphics3.getShader()->getUniLoc("diffuseColor");

		graphics4.setMesh(me4);
		graphics4.setShader(sh4);
		graphics4.setTexture(te4);

		graphics4.setupShaders("/home/bill/pxlShader.txt", "/home/bill/vrtShader.txt");
		graphics4.getShader()->apply();
		graphics4.getShader()->getUniLoc("rotation");
		graphics4.getShader()->getUniLoc("inv");
		graphics4.getShader()->getUniLoc("normalMat");
		graphics4.getShader()->getUniLoc("specColor");
		graphics4.getShader()->getUniLoc("lightPos");
		graphics4.getShader()->getUniLoc("camPos");
		graphics4.getShader()->getUniLoc("diffuseColor");

		graphics5.setMesh(me5);
		graphics5.setShader(sh5);
		graphics5.setTexture(te5);

		graphics5.setupShaders("/home/bill/pxlShader2.txt", "/home/bill/vrtShader2.txt");
		graphics5.getShader()->apply();
		graphics5.getShader()->getUniLoc("projection");
		graphics5.getShader()->getUniLoc("view");
		graphics5.getShader()->getUniLoc("rotation");
		graphics5.getShader()->getUniLoc("inv");
		graphics5.getShader()->getUniLoc("normalMat");
		graphics5.getShader()->getUniLoc("specColor");
		graphics5.getShader()->getUniLoc("lightPos");
		graphics5.getShader()->getUniLoc("diffuseColor");
		graphics5.getShader()->getUniLoc("camPos");

		lines.setShader(li);
		lines.setupShaders("/home/bill/lpxlShader.txt", "/home/bill/lShader.txt");
		lines.getShader()->apply();
		lines.getShader()->getUniLoc("rotation");
		lines.getShader()->getUniLoc("color");
		lines.getShader()->setUniVec("color", fdVector(0,0,1));

		light.setColor(1, 1, 1);
		light.setPos(0, 0, -5);
		light.setIntensity(2.0f);
		light.setDif(0.1f, 0.1f, 0.1f);
		light.setNode(graphics);

		light2.setColor(1, 1, 1);
		light2.setPos(0, 0, -5);
		light2.setIntensity(2.0f);
		light2.setDif(0.1f, 0.1f, 0.1f);
		light2.setNode(graphics2);

		light3.setColor(1, 1, 1);
		light3.setPos(0, 0, -5);
		light3.setIntensity(2.0f);
		light3.setDif(0.1f, 0.1f, 0.1f);
		light3.setNode(graphics3);

		light4.setColor(1, 1, 1);
		light4.setPos(0, 0, -5);
		light4.setIntensity(2.0f);
		light4.setDif(0.1f, 0.1f, 0.1f);
		light4.setNode(graphics4);

		light5.setColor(1, 1, 1);
		light5.setPos(0, 0, -5);
		light5.setIntensity(2.0f);
		light5.setDif(0.1f, 0.1f, 0.1f);


        graphics.getShader()->apply();
		graphics.getTexture()->setUp("/home/bill/Downloads/517.jpeg", graphics.getShader()->getProgram());
		graphics.getTexture()->generateTexture();
		graphics.getShader()->setUniInt("inv", 1);


		graphics2.getShader()->apply();
		graphics2.getTexture()->setUp("/home/bill/Downloads/517.jpeg", graphics2.getShader()->getProgram());
		graphics2.getTexture()->generateTexture();
		graphics2.getShader()->setUniInt("inv", 1);


		graphics3.getShader()->apply();
		graphics3.getTexture()->setUp("/home/bill/Desktop/assets/9436.jpg", graphics3.getShader()->getProgram());
		graphics3.getTexture()->generateTexture();
		graphics3.getShader()->setUniInt("inv", 1);


		graphics4.getShader()->apply();
		graphics4.getTexture()->setUp("/home/bill/Desktop/assets/9436.jpg", graphics4.getShader()->getProgram());
		graphics4.getTexture()->generateTexture();
		graphics4.getShader()->setUniInt("inv", 1);


		graphics5.getShader()->apply();
		graphics5.getTexture()->setUp("/home/bill/Desktop/assets/9436.jpg", graphics5.getShader()->getProgram());
		graphics5.getTexture()->generateTexture();
		graphics5.getShader()->setUniInt("inv", 1);
		glEnable(GL_DEPTH_TEST);

		// set clear color to gray
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		gnodes.push_back(graphics);
		gnodes.push_back(graphics2);
		gnodes.push_back(graphics3);
		gnodes.push_back(graphics4);
		gnodes.push_back(graphics5);
		light5.setNode(gnodes[4]);


		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
/**
*/
void Sweep()
{

}

void
ExampleApp::Run()
{
	fdMatrix d;
	d.set_RotationX(135);

	fdVector lp(light.getPos()[0], light.getPos()[1], light.getPos()[2]);



	gnodes[0].getMesh()->colP.setUpVec(fdVector(0,0,-1, 1));
	gnodes[0].getMesh()->colP.P.point = fdVector(0,0,0, 1);
	gnodes[0].getMesh()->rot.translation_Mat(fdVector(0,0,0, 1));
	gnodes[0].getMesh()->colP.id = "G1";
	gnodes[0].getMesh()->hasPlane = true;

	gnodes[1].getMesh()->colP.setUpVec(fdVector(0,0,-1, 1));
	gnodes[1].getMesh()->colP.P.point = fdVector(-5,0,0, 1);
	gnodes[1].getMesh()->rot.translation_Mat(fdVector(-5,0,0, 1));
	gnodes[1].getMesh()->colP.id = "G2";
	gnodes[1].getMesh()->hasPlane = true;


	gnodes[2].getMesh()->aabb.pos = fdVector(0, -10, 0);
	gnodes[2].getMesh()->aabb.setupAABB(2);
	gnodes[2].getMesh()->rot.translation_Mat(fdVector(0, -10, 0));
	gnodes[2].getMesh()->hasAABB = true;
	gnodes[2].getMesh()->hasPlane = false;
	gnodes[2].getMesh()->position = fdVector(0, -10, 0);
	gnodes[2].getMesh()->CoM = fdVector(0, -10, 0);
	gnodes[2].getMesh()->mass = 0;


    gnodes[3].getMesh()->aabb.pos = fdVector(-2.5f, 10, 0.f);
    gnodes[3].getMesh()->aabb.setupAABB(3);
    gnodes[3].getMesh()->rot.translation_Mat(fdVector(-2.5f, 10, -0.0f));
    gnodes[3].getMesh()->hasAABB = true;
    gnodes[3].getMesh()->hasPlane = false;
    gnodes[3].getMesh()->position = fdVector(-2.5f, 10, 0.f);
    gnodes[3].getMesh()->calcCoM(1.0f);
    gnodes[3].getMesh()->calcITens();


    gnodes[4].getMesh()->aabb.pos = fdVector(2.5f, 10, 0.f);
	gnodes[4].getMesh()->aabb.setupAABB(4);
	gnodes[4].getMesh()->rot.translation_Mat(fdVector(2.5f, 10, 0.f));
	gnodes[4].getMesh()->rot.set_Position(2.5f, 10, 0.f);
	gnodes[4].getMesh()->hasAABB = true;
	gnodes[4].getMesh()->hasPlane = false;
	gnodes[4].getMesh()->calcCoM(1.0f);
    gnodes[4].getMesh()->calcITens();

	vector<AABB*> bboxes;
    bboxes.push_back(&gnodes[2].getMesh()->aabb);
	bboxes.push_back(&gnodes[3].getMesh()->aabb);
	bboxes.push_back(&gnodes[4].getMesh()->aabb);

	bool blah = true;

	float rotate = M_2_PI;
	while (this->window->IsOpen()) {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();

		float cosPitch = cos(pitch);
		float sinPitch = sin(pitch);
		float cosYaw = cos(yaw);
		float sinYaw = sin(yaw);

		xAxis = {cosYaw, 0, -sinYaw};
		yAxis = {sinYaw * sinPitch, cosPitch, cosYaw * sinPitch};
		zAxis = {sinYaw * cosPitch, -sinPitch, cosPitch * cosYaw};


		int width, height;
		glfwGetWindowSize(window->getWindow(), &width, &height);
		fdVector forward = zAxis.normalize() * yAcc * 0.01;
		fdVector right = xAxis.normalize() * xAcc * 0.01;


		target = fdVector(0, 0, -1);


		eye = eye + forward + right;


		viewMatrix = fdMatrix(xAxis.get_X(), xAxis.get_Y(), xAxis.get_Z(), -(xAxis.dot(eye)),
							  yAxis.get_X(), yAxis.get_Y(), yAxis.get_Z(), -(yAxis.dot(eye)),
							  zAxis.get_X(), zAxis.get_Y(), zAxis.get_Z(), -(zAxis.dot(eye)),
							  0, 0, 0, 1);

		glfwGetWindowSize(window->getWindow(), &width, &height);

		float aspect = (float) height / (float) width;
		float fov = 90.0f;        //Field of view
		float near = 0.1f;        //Near clipping plane
		float far = 10000.0f;        //Far clipping plane
		float top = near * (tan((fov / 2.0f) * (M_PI / 180.0f)));
		float r = top * aspect;        //Far clipping plane



		projectionMatrix = fdMatrix((near) / (r), 0, 0, 0,
									0, (near) / (top), 0, 0,
									0, 0, (-1 * (far + near) / (far - near)), (-1 * (2 * far * near) / (far - near)),
									0, 0, -1, 0);


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		this->window->Update();


        //applyGravity
        //gnodes[3].getMesh()->applyForce(gnodes[3].getMesh()->CoM, fdVector(0, -1, 0), dt, 0.3);
        //gnodes[4].getMesh()->applyForce(gnodes[4].getMesh()->CoM, fdVector(0, -1, 0), dt, 0.3);
        gnodes[3].struck = true;
        gnodes[4].struck = true;
        //

		gnodes[0].setMat(projectionMatrix * viewMatrix * gnodes[0].getMesh()->rot);
		gnodes[0].getShader()->setUniVec("camPos", eye);

		gnodes[0].draw();
		gnodes[0].getShader()->setUniMat("normalMat", viewMatrix.makeminverse(gnodes[0].getMesh()->rot).make_Tran());
		light.setUniform();


		gnodes[1].setMat(projectionMatrix * viewMatrix * gnodes[1].getMesh()->rot);
		gnodes[1].getShader()->setUniVec("camPos", eye);

		gnodes[1].draw();
		gnodes[1].getShader()->setUniMat("normalMat", viewMatrix.makeminverse(gnodes[1].getMesh()->rot).make_Tran());

		light2.setUniform();


		gnodes[2].setMat(projectionMatrix * viewMatrix * gnodes[2].getMesh()->rot);
		gnodes[2].getShader()->setUniVec("camPos", eye);

		gnodes[2].draw();
		gnodes[2].getShader()->setUniMat("normalMat", viewMatrix.makeminverse(viewMatrix * gnodes[2].getMesh()->rot).make_Tran());

        gnodes[2].getMesh()->updateOBJ(dt);

        gnodes[2].getMesh()->rotateOOBB();
		light3.setUniform();


		fdMatrix rx, ry, rz, rc;

		rx.set_Position(-xAccM/500.0f, -yAccM/500.0f, 0);
		ry.set_RotationY(rotate / 120);
		rz.set_RotationZ(rotate / 200);

		gnodes[3].getMesh()->rot = rx * gnodes[3].getMesh()->rot;

		gnodes[3].setMat(projectionMatrix * viewMatrix * gnodes[3].getMesh()->rot);
		gnodes[3].getShader()->setUniVec("camPos", eye);

		gnodes[3].draw();
		gnodes[3].getShader()->setUniMat("normalMat", viewMatrix.makeminverse(gnodes[3].getMesh()->rot).make_Tran());
		if (gnodes[3].struck) {
			gnodes[3].getMesh()->updateOBJ(dt);
		}
		gnodes[3].getMesh()->rotateOOBB();
		light4.setUniform();

		gnodes[4].getShader()->apply();

		light5.setPos(eye[0], eye[1], eye[2]);
		light5.setUniform();
		gnodes[4].getShader()->setUniMat("normalMat", viewMatrix.makeminverse(gnodes[4].getMesh()->rot).make_Tran());
		gnodes[4].getShader()->setUniMat("projection", projectionMatrix);
		gnodes[4].getShader()->setUniMat("view", viewMatrix);
		gnodes[4].getShader()->setUniMat("rotation", gnodes[4].getMesh()->rot);
		gnodes[4].getShader()->setUniVec("camPos", eye);
		gnodes[4].setMat(projectionMatrix * viewMatrix * gnodes[4].getMesh()->rot);
		gnodes[4].draw();
		if (gnodes[4].struck) {
			gnodes[4].getMesh()->updateOBJ(dt);
		}
		gnodes[4].getMesh()->rotateOOBB();


		lines.getShader()->apply();
		lines.getShader()->setUniMat("rotation", projectionMatrix * viewMatrix);
		gnodes[3].getMesh()->aabb.drawAABB();
		gnodes[4].getMesh()->aabb.drawAABB();
		gnodes[4].getMesh()->drawOOBB();
		gnodes[3].getMesh()->drawOOBB();

		glPointSize(6);
		glBegin(GL_POINTS);
		glVertex3f(eye[0] - zAxis[0], eye[1] - zAxis[1], eye[2] - zAxis[2]);
		glEnd();
		//glutWarpPointer(384,512);



		if (lpress && once) {

			ray.direction = zAxis.normalize() * -1;
			ray.start = eye;


			vector<int> hits;
			vector<fdVector> hitsv;
			for (int i = 0; i < gnodes.size(); i++) {
				r1 = ray.checkIntersect(gnodes[i].getMesh()->colP);

				if (r1.get_W() != 9999) {
					//cout << r1.get_Vector() << " G1" << endl << endl;
					if ((r1.get_X() >
						 (-gnodes[i].getMesh()->boundsMax.get_X() + gnodes[i].getMesh()->colP.P.point.get_X()) - 0.01 &&
						 r1.get_X() <=
						 (gnodes[i].getMesh()->boundsMax.get_X() + gnodes[i].getMesh()->colP.P.point.get_X()) + 0.01) &&
						(r1.get_Y() >
						 (-gnodes[i].getMesh()->boundsMax.get_Y() + gnodes[i].getMesh()->colP.P.point.get_Y()) - 0.01 &&
						 r1.get_Y() <=
						 (gnodes[i].getMesh()->boundsMax.get_Y() + gnodes[i].getMesh()->colP.P.point.get_Y()) + 0.01) &&
						(r1.get_Z() >
						 (-gnodes[i].getMesh()->boundsMax.get_Z() + gnodes[i].getMesh()->colP.P.point.get_Z()) - 0.01 &&
						 r1.get_Z() <=
						 (gnodes[i].getMesh()->boundsMax.get_Z() + gnodes[i].getMesh()->colP.P.point.get_Z()) + 0.01) &&
							gnodes[i].getMesh()->hasPlane)
					{
						hits.push_back(i);
						hitsv.push_back(r1);
					}
				}
			}

			for (int k = 0; k < gnodes.size(); ++k) {
				if (gnodes[k].getMesh()->hasAABB) {
					r1 = ray.checkIntersect(gnodes[k].getMesh()->aabb);
					if (r1.get_W() != 9999) {
						hits.push_back(k);
						hitsv.push_back(r1);
					}
				}
			}

			float closest = 9999999;
			int hid;
			int line;
			for (int j = 0; j < hits.size(); ++j) {
				fdVector comp = hitsv[j] - ray.start;
				float cl = comp.length();
				if (cl < closest) {
					closest = cl;
					hid = hits[j];
					line = j;
					lHit = hitsv[j];
				};
			}
			if (hits.size() != 0) {
				gnodes[hid].getMesh()->applyForce(lHit, ray.direction, dt, 2);
			if (gnodes[hid].struck) {
//					gnodes[hid].getShader()->apply();
//					gnodes[hid].getShader()->setUniInt("inv", 0);
					gnodes[hid].struck = true;
				} else {
//					gnodes[hid].getShader()->apply();
//					gnodes[hid].getShader()->setUniInt("inv", 1);
					gnodes[hid].struck = true;
				}

			}
			once = false;
		}

		lines.getShader()->apply();
		glPointSize(6);
		glBegin(GL_POINTS);
		glVertex3f(eye[0] - zAxis[0], eye[1] - zAxis[1], eye[2] - zAxis[2]);
		glVertex3f(lHit[0], lHit[1], lHit[2]);

		glVertex3f(0, 0, 0);
		glEnd();


		glPointSize(10);
		glBegin(GL_POINTS);
		glVertex3f(0, 0, 0);
		glEnd();

        int sweepTest = LinearSweep(bboxes).size();
        vector<collision> colList = LinearSweep(bboxes);
        if (sweepTest > 0)
		{
			fdVector colNorm;
			fdVector colPos;
			float depth;
            for (int i = 0; i < sweepTest; ++i) {
                if(GJK(gnodes[bboxes[colList[i].ID1]->owner], gnodes[bboxes[colList[i].ID2]->owner], colNorm, colPos, depth))
                {
                    cout <<"Collision norm: " <<  colNorm.get_Vector() << "Collision point : "  << colPos.get_Vector() << " Collision depth: " << depth << endl << endl;

                    collRespo(gnodes[bboxes[colList[i].ID1]->owner], gnodes[bboxes[colList[i].ID2]->owner], colNorm, colPos, depth, dt);
                }
            }

		}


		this->window->SwapBuffers();
        end = std::chrono::system_clock::now();
        dt = (double)std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()/1000.f;
	}
}

} // namespace Example