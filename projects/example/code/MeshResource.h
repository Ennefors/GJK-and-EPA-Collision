#include <vector>
#include "AABB.h"
#include "core/app.h"


class MeshResource {
	struct vertex {
		fdVector pos;
		fdVector uv;
		fdVector norm;
	};


private:
	GLuint vbo, ebo;
	unsigned int indexCount;
	vertex *vertBuffer;
	int *intBuffer;
	int vertBufSize;
	int intBufSize;
public:
	bool hasAABB = false;
	bool hasPlane = false;


	MeshResource() {};

	~MeshResource() {
		glDeleteBuffers(sizeof(vertex) * vertBufSize, &vbo);
		glDeleteBuffers(sizeof(int) * intBufSize, &vbo);
	};

	static MeshResource *createCube();

	static MeshResource *loadObj(char *);

	void setUp(int, vertex *, int, int *);

	void draw();

	Plane colP;
	fdVector boundsMin;
	fdVector boundsMax;
	fdMatrix rot;
	fdMatrix oldRot;
	fdMatrix difRot;
	fdMatrix symmetricSkew;
	fdMatrix iT;
	fdMatrix iIT;
	fdMatrix inertiaTensor;
	fdMatrix invInertiaTensor;

	fdVector angMomentum;
	fdVector CoM;
	fdVector direction;
	fdVector spinVec;
	fdVector linVel;
	fdVector torque;
	fdVector position;

	float mass;
	float massP;
	float accel;
	float vel;

	////Calculates initial inertia tensor of the base model.
	inline void calcITens()
	{
		float xx = 0.0f;
		float yy = 0.0f;
		float zz = 0.0f;
		float xy = 0.0f;
		float xz = 0.0f;
		float yz = 0.0f;

		for (int i = 0; i < this->vertBufSize; ++i)
		{
			fdVector v = this->vertBuffer[i].pos;
			xx += this->massP * (v[1]*v[1] + v[2]*v[2]);
			yy += this->massP * (v[0]*v[0] + v[2]*v[2]);
			zz += this->massP * (v[0]*v[0] + v[1]*v[1]);

			xy += this->massP * v[0] * v[1];
			xz += this->massP * v[0] * v[2];
			yz += this->massP * v[1] * v[2];
		}
		fdMatrix ro = this->rot;
		ro.set_Position(0,0,0);
		fdMatrix inert = fdMatrix( xx, -xy, -xz, 0,
								   -xy,  yy, -yz, 0,
								   -xz, -yz,  zz, 0,
								   0,   0,   0,  1);
		fdMatrix invInert = inert.makeminverse(inert);
		fdMatrix tranRot = ro.make_Tran();
		this->iT = inert;
		this->iIT = invInert;
		inert = ro*inert;
		inert = inert*tranRot;

		invInert = ro*invInert;
		invInert = invInert*tranRot;

		this->inertiaTensor = inert;
		this->invInertiaTensor = invInert;
	}

	////Calculates the inverse inertia tensor, done every frame.
	inline void calcITens2()
	{
		fdMatrix ro = this->rot;
		ro.set_Position(0,0,0);
		fdMatrix invInert = this->iIT;
		fdMatrix tranRot = ro.make_Tran();

		invInert = ro*invInert;
		invInert = invInert*tranRot;

		this->invInertiaTensor = invInert;
	}

	inline const void calcCoM(const float w)
	{
		for (int i = 0; i < this->vertBufSize; ++i)
		{
			this->CoM = this->CoM + this->vertBuffer[i].pos * w;

		}
		this->CoM = this->CoM*(1.0f/(float)vertBufSize);
		this->CoM = this->CoM + this->position;
		this->mass = w * this->vertBufSize;
		this->massP  = w;
	};

	////calculates the spin
	inline const void calcSpin()
	{

		fdVector sp = this->invInertiaTensor.trans_tdVector(this->torque);
		this->spinVec = this->invInertiaTensor.trans_tdVector(this->angMomentum);
        this->symmetricSkew = fdMatrix( 0,               -this->spinVec[2],   this->spinVec[1], 0,
                                        this->spinVec[2],  0,                -this->spinVec[0], 0,
                                        -this->spinVec[1], this->spinVec[0],  0,                0,
                                        0,                 0,                 0,                1);
	};

	////calculates the Torque vector
	inline const void calcTorque(fdVector col, fdVector dir, float f)
	{

		fdVector v = col - this->CoM;
		this->torque = (v).Cross(dir.normalize() * f);
		this->angMomentum = this->angMomentum + this->torque;
	};


	inline void calcVel(float f, float dt, fdVector dir)
	{
		this->vel = (f/this->mass)*dt;
		this->direction = this->direction + dir*vel;
	}


	inline void calcRot(float dt)
	{
        fdMatrix DR = (this->rot * this->symmetricSkew)*dt;
		fdMatrix d;
		//d.set_Rotation(this->spinVec, this->angMomentum.length());s

		//this->rot.set_Position(this->CoM[0],this->CoM[1],this->CoM[2]);

		this->rot = (this->rot + DR);
		this->rot.otrhoNorm();
        this->CoM = this->rot.trans_tdVector(this->CoM);
	}


	inline void applyForce(fdVector rayCol, fdVector rayDir, float dt, float force)
	{
		this->position = this->rot.get_Position();
		calcTorque(rayCol, rayDir, force);
		calcVel(force, dt, rayDir);
		calcITens2();
		calcSpin();
	}


	inline void updateOBJ(float dt)
	{
		this->position = this->rot.get_Position() + direction;
		calcITens2();
		calcSpin();
		calcRot(dt);
		this->rot.set_Position(this->position[0], this->position[1], this->position[2]);

	};


	inline void rotateOOBB()
	{
		fdVector mi(9999999999999, 9999999999999, 9999999999999), ma(-9999999999999, -9999999999999, -9999999999999);
		for (int i = 0; i < this->OOBBbase.size(); ++i)
		{
			this->OOBB[i] = rot.make_Tran().trans_tdVector(this->OOBBbase[i]);
			mi = fdVector(min(mi[0], this->OOBB[i][0]), min(mi[1], this->OOBB[i][1]), min(mi[2], this->OOBB[i][2]));
			ma = fdVector(max(ma[0], this->OOBB[i][0]), max(ma[1], this->OOBB[i][1]), max(ma[2], this->OOBB[i][2]));
		}
		this->aabb.max = ma;
		this->aabb.min = mi;
		this->aabb.pos = rot.get_Position();
	}


	inline fdVector getFarthestPointInDirection(fdVector direction)
	{
		float l = -999999;
		int ID;
		for (int i = 0; i < this->OOBB.size(); ++i) {

			float s = this->OOBB[i].dot(direction);
			if(s > l)
			{
				l = s;
				ID = i;
			}
		}
		return this->OOBB[ID];
	};

	inline void drawOOBB()
	{
		glLineWidth(2.5);

		glBegin(GL_LINES);
		glVertex3f(this->OOBB[0][0] , this->OOBB[0][1], this->OOBB[0][2]);
		glVertex3f(this->OOBB[1][0] , this->OOBB[1][1], this->OOBB[1][2]);

		glVertex3f(this->OOBB[1][0] , this->OOBB[1][1], this->OOBB[1][2]);
		glVertex3f(this->OOBB[2][0] , this->OOBB[2][1], this->OOBB[2][2]);

		glVertex3f(this->OOBB[2][0] , this->OOBB[2][1], this->OOBB[2][2]);
		glVertex3f(this->OOBB[3][0] , this->OOBB[3][1], this->OOBB[3][2]);

		glVertex3f(this->OOBB[3][0] , this->OOBB[3][1], this->OOBB[3][2]);
		glVertex3f(this->OOBB[0][0] , this->OOBB[0][1], this->OOBB[0][2]);

		glVertex3f(this->OOBB[0][0] , this->OOBB[0][1], this->OOBB[0][2]);
		glVertex3f(this->OOBB[6][0] , this->OOBB[6][1], this->OOBB[6][2]);

		glVertex3f(this->OOBB[7][0] , this->OOBB[7][1], this->OOBB[7][2]);
		glVertex3f(this->OOBB[4][0] , this->OOBB[4][1], this->OOBB[4][2]);

		glVertex3f(this->OOBB[4][0] , this->OOBB[4][1], this->OOBB[4][2]);
		glVertex3f(this->OOBB[5][0] , this->OOBB[5][1], this->OOBB[5][2]);

		glVertex3f(this->OOBB[5][0] , this->OOBB[5][1], this->OOBB[5][2]);
		glVertex3f(this->OOBB[3][0] , this->OOBB[3][1], this->OOBB[3][2]);

		glVertex3f(this->OOBB[5][0] , this->OOBB[5][1], this->OOBB[5][2]);
		glVertex3f(this->OOBB[6][0] , this->OOBB[6][1], this->OOBB[6][2]);

		glVertex3f(this->OOBB[6][0] , this->OOBB[6][1], this->OOBB[6][2]);
		glVertex3f(this->OOBB[7][0] , this->OOBB[7][1], this->OOBB[7][2]);

		glVertex3f(this->OOBB[7][0] , this->OOBB[7][1], this->OOBB[7][2]);
		glVertex3f(this->OOBB[1][0] , this->OOBB[1][1], this->OOBB[1][2]);

		glVertex3f(this->OOBB[2][0] , this->OOBB[2][1], this->OOBB[2][2]);
		glVertex3f(this->OOBB[4][0] , this->OOBB[4][1], this->OOBB[4][2]);


		glEnd();
	}

	vector<fdVector> OOBBbase;
	vector<fdVector> OOBB;
	AABB aabb;
};
