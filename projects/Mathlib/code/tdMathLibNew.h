#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

class fdVector
{
	private:
		float fdVctr[4];

	public:
		//Create a vector that's empty
		fdVector::fdVector()
		{
			set_Vector(0, 0, 0, 1);
		}
		//Create a vector with set x, y and z values
		fdVector::fdVector(float x, float y, float z)
		{
			set_Vector(x, y, z, 1);
		}
		//Create a vector with set x, y, z and w values 
		fdVector::fdVector(float x, float y, float z, float w)
		{
			set_Vector(x, y, z, w);
		}
		//Create a vector as a copy of another
		fdVector::fdVector(const fdVector& v)
		{
			set_Vector(v.fdVctr[0], v.fdVctr[1], v.fdVctr[2]);
		}
		//Set X, Y, Z and W values of the vector
		void fdVector::set_Vector(float x, float y, float z, float w)
		{
			fdVctr[0] = x;
			fdVctr[1] = y;
			fdVctr[2] = z;
			fdVctr[3] = w;
		}
		//Set X, Y and Z values of the vector
		void fdVector::set_Vector(float x, float y, float z)
		{
			fdVctr[0] = x;
			fdVctr[1] = y;
			fdVctr[2] = z;
		}
		//Sets the X value
		void fdVector::set_X(float x)
		{
			fdVctr[0] = x;
		}
		
		//sets the Y value
		void fdVector::set_Y(float y)
		{
			fdVctr[1] = y;
		}
		//Sets the Z value
		void fdVector::set_Z(float z)
		{
			fdVctr[2] = z;
		}
		//Sets the W value
		void fdVector::set_W(float w)
		{
			fdVctr[3] = w;
		}
		//Gets a vector (Mainly for test)
		string fdVector::get_Vector()
		{
			stringstream vect(stringstream::in | stringstream::out);

			vect << "(" << get_X() << "," << get_Y() << "," << get_Z() << "," << get_W() <<")" ;
			string svect = vect.str();

			return svect;
		}
		//Gets the X value
		float fdVector::get_X() const
		{
			return fdVctr[0];
		}
		//Gets the Y value 
		float fdVector::get_Y() const
		{
			return fdVctr[1];
		}
		//Gets the Z value
		float fdVector::get_Z() const
		{
			return fdVctr[2];
		}
		//Gets the W value or the fourth value
		float fdVector::get_W() const
		{
			return fdVctr[3];
		}
		//adds a vector to another
		fdVector fdVector::add (fdVector addV)
		{
			fdVector result;
			result.set_X(get_X() + addV.get_X());
			result.set_Y(get_Y() + addV.get_Y());
			result.set_Z(get_Z() + addV.get_Z());
			return result;
		}
		//subtracts a vector from another
		fdVector fdVector::sub (fdVector subV)
		{
			fdVector result;
			result.set_X(get_X() - subV.get_X());
			result.set_Y(get_Y() - subV.get_Y());
			result.set_Y(get_Y() - subV.get_Z());
			return result;
		}

		//calculates dot product of vectors
		float fdVector::dot(fdVector dotV)
		{
			float dotVal = ((get_X()*dotV.get_X()) + (get_Y()*dotV.get_Y()) + (get_Z()*dotV.get_Z()));
			return dotVal;
		}

		//calculates length of a vector
		float fdVector::length()
		{
			float length = sqrt(pow(get_X(), 2) + pow(get_Y(), 2) + pow(get_Z(), 2));
			return length;
		}

		fdVector fdVector::normalize() const
		{
			float x, y, z, w;
			float l = sqrt(pow(get_X(), 2) + pow(get_Y(), 2) + pow(get_Z(), 2));
			if (l == 0) {
				throw exception("Vector is null");
			}
			return fdVector(x / l, y / l, z / l, w / l);
		}
		//compares two vectors
		bool fdVector::equalV(fdVector compV)
		{
			if (get_X() == compV.get_X() && get_Y() == compV.get_Y() && get_Z() == compV.get_Z() && get_W() == compV.get_W()) {
				return true;
			}
			else {
				return false;
			}
		}

		//addition opperator override
		fdVector fdVector::operator+ (const fdVector& v)
		{
			return add(v);
		}
		
		//subtraction opperator override
		fdVector fdVector::operator- (const fdVector& v)
		{
			return sub(v);
		}

		//=operator override
		fdVector& fdVector::operator= (const fdVector v)
		{
			set_Vector(v.get_X(), v.get_Y(), v.get_Z());
			return *this;
		}
		// dot product of vector override
		float fdVector::operator* (const fdVector& v)
		{
			return dot(v);
		}
		//Multiply vector with a single value opperator override
		fdVector fdVector::operator* (const float& v)
		{
			fdVector temp;
			temp.set_Vector(get_X()*v, get_Y()*v, get_Z());
			return temp;
		}
		//==opperator override
		bool fdVector::operator== (const fdVector& v)
		{
			if (equalV(v)) {
				return true;
			}
			else {
				return false;
			}
		}
		//!= opperator override
		bool fdVector::operator!= (const fdVector& v)
		{
			if (equalV(v)) {
				return false;
			}
			else {
				return true;
			}
		}
};


class fdMatrix
{
	private:
		float fdMat[4][4];


	public:
		//Creates a basic matrix
		fdMatrix::fdMatrix(void)
		{
			for (int i = 0; i <= 3; i++) {
				for (int k = 0; k <= 3; k++) {
					fdMat[i][k] = 0;
				}
			}
			fdMat[0][0] = 1;
			fdMat[1][1] = 1;
			fdMat[2][2] = 1;
			fdMat[3][3] = 1;
		}
		//Creates a matrix with set values
		fdMatrix::fdMatrix(float one, float two, float thr, float fou, float fiv, float six, float sev, float eig, float nin, float ten, float ele, float twe, float thi, float fot, float fif, float sit)
		{
			fdMat[0][0] = one;
			fdMat[0][1] = two;
			fdMat[0][2] = thr;
			fdMat[0][3] = fou;
			fdMat[1][0] = fiv;
			fdMat[1][1] = six;
			fdMat[1][2] = sev;
			fdMat[1][3] = eig;
			fdMat[2][0] = nin;
			fdMat[2][1] = ten;
			fdMat[2][2] = ele;
			fdMat[2][3] = twe;
			fdMat[3][0] = thi;
			fdMat[3][1] = fot;
			fdMat[3][2] = fif;
			fdMat[3][3] = sit;
		}
		//Creates a matrix as a copy of another
		fdMatrix::fdMatrix(const fdMatrix& copy)
		{
			fdMat[0][0] = copy.fdMat[0][0];
			fdMat[0][1] = copy.fdMat[0][1];
			fdMat[0][2] = copy.fdMat[0][2];
			fdMat[0][3] = copy.fdMat[0][3];
			fdMat[1][0] = copy.fdMat[1][0];
			fdMat[1][1] = copy.fdMat[1][1];
			fdMat[1][2] = copy.fdMat[1][2];
			fdMat[1][3] = copy.fdMat[1][3];
			fdMat[2][0] = copy.fdMat[2][0];
			fdMat[2][1] = copy.fdMat[2][1];
			fdMat[2][2] = copy.fdMat[2][2];
			fdMat[2][3] = copy.fdMat[2][3];
			fdMat[3][0] = copy.fdMat[3][0];
			fdMat[3][1] = copy.fdMat[3][1];
			fdMat[3][2] = copy.fdMat[3][2];
			fdMat[3][3] = copy.fdMat[3][3];
		}
		//Gets an element
		float fdMatrix::get_Element(int row, int col)
		{
			if (row > 3 || col > 3 || row < 0 || col < 0) {
				cerr << "ERROR: Trying to reach outside of matrix" << endl;
				return -1;
			}

			return fdMat[row][col];
		}
		//Gets the matrix
		float& fdMatrix::get_Mat()
		{
			float** fdMatPoint;
			fdMatPoint = new float*[4];
			fdMatPoint[1] = new float[4];
			fdMatPoint[2] = new float[4];
			fdMatPoint[3] = new float[4];
			fdMatPoint[4] = new float[4];
			for (int i = 0; i <= 3; i++) {
				for (int j = 0; i <= 3; j++) {
					fdMatPoint[i][j] = fdMat[i][j];
				}
			}
			return **fdMatPoint;
		}
		//Set an element in the matrix
		void fdMatrix::set_Element(int row, int col, float ele)
		{
			if (row > 4 || col > 4 || row < 0 || col < 0) {
				cerr << "ERROR: Trying to reach outside of matrix" << endl;
				return;
			}
			fdMat[(row)][col] = ele;
		}
		//Set a row in the matrix
		void fdMatrix::set_Row(int row, float l, float ml, float mr, float r)
		{
			if (row > 3 || row < 0) {
				cerr << "ERROR: Trying to reach outside of matrix" << endl;
				return;
			}
			fdMat[(row)][0] = l;
			fdMat[(row)][1] = ml;
			fdMat[(row)][2] = mr;
			fdMat[(row)][3] = r;
		}
		//Set a column in the matrix
		void fdMatrix::set_Col(int col, float t, float mt, float mb, float b)
		{
			if (col > 4 || col < 0) {
				cerr << "ERROR: Trying to reach outside of matrix" << endl;
				return;
			}
			fdMat[0][col] = t;
			fdMat[1][col] = mt;
			fdMat[2][col] = mb;
			fdMat[3][col] = b;
		}
		//Set all values in the matrix
		void fdMatrix::set_Mat(float one, float two, float thr, float fou, float fiv, float six, float sev, float eig, float nin, float ten, float ele, float twe, float thi, float fot, float fif, float sit)
		{
			fdMat[0][0] = one;
			fdMat[0][1] = two;
			fdMat[0][2] = thr;
			fdMat[0][3] = fou;

			fdMat[1][0] = fiv;
			fdMat[1][1] = six;
			fdMat[1][2] = sev;
			fdMat[1][3] = eig;

			fdMat[2][0] = nin;
			fdMat[2][1] = ten;
			fdMat[2][2] = ele;
			fdMat[2][3] = twe;

			fdMat[3][0] = thi;
			fdMat[3][1] = fot;
			fdMat[3][2] = fif;
			fdMat[3][3] = sit;
		}
		//Sets the position of the matrix
		void fdMatrix::set_Position(float x, float y, float z)
		{
			fdMat[0][3] = x;
			fdMat[1][3] = y;
			fdMat[2][3] = z;
		}
		//Makes transosed matrix
		fdMatrix  fdMatrix::make_Tran()
		{
			fdMatrix tran;
			float temp;
			temp = fdMat[0][1];
			tran.fdMat[0][1] = fdMat[1][0];
			tran.fdMat[1][0] = temp;

			temp = fdMat[0][2];
			tran.fdMat[0][2] = fdMat[2][0];
			tran.fdMat[2][0] = temp;

			temp = fdMat[1][2];
			tran.fdMat[1][2] = fdMat[2][1];
			tran.fdMat[2][1] = temp;
			return tran;
		}
		//Makes a translation matrix for a vector
		void fdMatrix::translation_Mat(fdVector v)
		{
			fdMat[0][3] = v.get_X();
			fdMat[1][3] = v.get_Y();
			fdMat[2][3] = v.get_Z();
		}
		//prints the matrix(for test)
		void fdMatrix::printMat()
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << fdMat[i][j] << " ";
				}
				cout << endl;
			}
		}
		// makes a trans vector
		fdVector fdMatrix::trans_tdVector(fdVector v)
		{
			fdVector trans;
			float x, y, z, w;
			x = get_Element(0, 0) * v.get_X() + get_Element(0, 1) * v.get_Y() + get_Element(0, 2) * v.get_Z() + get_Element(0, 3) * v.get_W();
			y = get_Element(1, 0) * v.get_X() + get_Element(1, 1) * v.get_Y() + get_Element(1, 2) * v.get_Z() + get_Element(1, 3) * v.get_W();
			z = get_Element(2, 0) * v.get_X() + get_Element(2, 1) * v.get_Y() + get_Element(2, 2) * v.get_Z() + get_Element(2, 3) * v.get_W();
			w = get_Element(3, 0) * v.get_X() + get_Element(3, 1) * v.get_Y() + get_Element(3, 2) * v.get_Z() + get_Element(3, 3) * v.get_W();
			trans.set_X(x);
			trans.set_Y(y);
			trans.set_Z(z);
			trans.set_W(w);
			return trans;
		}
		//rotates around X axis
		void fdMatrix::set_RotationX(float x)
		{
			float cosVal = cos(x);
			float smatal = sin(x);
			fdMat[1][1] = cosVal;
			fdMat[1][2] = -smatal;
			fdMat[2][1] = smatal;
			fdMat[2][2] = cosVal;
		}
		//Rotates around Y axis
		void fdMatrix::set_RotationY(float y)
		{
			float cosVal = cos(y);
			float smatal = sin(y);
			fdMat[0][0] = cosVal;
			fdMat[0][2] = -smatal;
			fdMat[2][0] = smatal;
			fdMat[2][2] = cosVal;
		}
		//Rotates around Z axis
		void fdMatrix::set_RotationZ(float z)
		{
			float cosVal = cos(z);
			float smatal = sin(z);
			fdMat[0][0] = cosVal;
			fdMat[0][1] = -smatal;
			fdMat[1][0] = smatal;
			fdMat[1][1] = cosVal;
		}
		//Rotates around a vector
		void fdMatrix::set_Rotation(fdVector v, float d)
		{
			float cosVal = cos(d);
			float smatal = sin(d);
			fdMat[0][0] = (v.get_X() * v.get_X()) + (1 - v.get_X() * v.get_X()) * cosVal;
			fdMat[0][1] = ((v.get_X() * v.get_Y() * (1 - cosVal)) - (v.get_X() * smatal));
			fdMat[0][2] = ((v.get_X() * v.get_Z() * (1 - cosVal)) + (v.get_Y() * smatal));
			

			fdMat[1][0] = ((v.get_X() * v.get_Y() * (1 - cosVal)) + (v.get_Z() * smatal));
			fdMat[1][1] = (v.get_Y() * v.get_Y()) + (1 - v.get_Y() * v.get_Y()) * cosVal;
			fdMat[1][2] = ((v.get_X() * v.get_Z() * (1 - cosVal)) - (v.get_X() * smatal));
		

			fdMat[2][0] = ((v.get_X() * v.get_Z() * (1 - cosVal)) - (v.get_Y() * smatal));
			fdMat[2][1] = ((v.get_Y() * v.get_Z() * (1 - cosVal)) + (v.get_X() * smatal));
			fdMat[2][2] = (v.get_Z() *v.get_Z()) + (1 - v.get_Z() * v.get_Z()) * cosVal;
			
		}

		fdVector fdMatrix::get_Position()
		{
			fdVector pos(fdMat[0][3], fdMat[1][3], fdMat[2][3]);
			return pos;
		}
		//Makes an inverse matrix
		fdMatrix fdMatrix::makeminverse(fdMatrix mat)
		{
			float det = mat.fdMat[0][0] * mat.fdMat[1][1] * mat.fdMat[2][2] * mat.fdMat[3][3] +
						mat.fdMat[0][0] * mat.fdMat[1][2] * mat.fdMat[2][3] * mat.fdMat[3][1] +
						mat.fdMat[0][0] * mat.fdMat[1][3] * mat.fdMat[2][1] * mat.fdMat[3][2] +

						mat.fdMat[0][1] * mat.fdMat[1][2] * mat.fdMat[2][0] * mat.fdMat[3][3] +
						mat.fdMat[0][1] * mat.fdMat[1][3] * mat.fdMat[2][2] * mat.fdMat[3][0] +
						mat.fdMat[0][1] * mat.fdMat[1][3] * mat.fdMat[2][2] * mat.fdMat[3][0] +
						
						mat.fdMat[0][2] * mat.fdMat[1][0] * mat.fdMat[2][1]	* mat.fdMat[3][3] +
						mat.fdMat[0][2] * mat.fdMat[1][1] * mat.fdMat[2][3] * mat.fdMat[3][0] + 
						mat.fdMat[0][2] * mat.fdMat[1][3] * mat.fdMat[2][0] * mat.fdMat[3][1] + 
				
						mat.fdMat[0][3] * mat.fdMat[1][0] * mat.fdMat[2][2] * mat.fdMat[3][1] + 
						mat.fdMat[0][3] * mat.fdMat[1][1] * mat.fdMat[2][0] * mat.fdMat[3][2] + 
						mat.fdMat[0][3] * mat.fdMat[1][2] * mat.fdMat[2][1] * mat.fdMat[3][0] -
				
						mat.fdMat[0][0] * mat.fdMat[1][1] * mat.fdMat[2][3] * mat.fdMat[3][2] -
						mat.fdMat[0][0] * mat.fdMat[1][2] * mat.fdMat[2][1] * mat.fdMat[3][3] -
						mat.fdMat[0][0] * mat.fdMat[1][3] * mat.fdMat[2][2] * mat.fdMat[3][1] -

						mat.fdMat[0][1] * mat.fdMat[1][0] * mat.fdMat[2][2] * mat.fdMat[3][3] -
						mat.fdMat[0][1] * mat.fdMat[1][2] * mat.fdMat[2][3] * mat.fdMat[3][0] -
						mat.fdMat[0][1] * mat.fdMat[1][3] * mat.fdMat[2][0] * mat.fdMat[3][2] -

						mat.fdMat[0][2] * mat.fdMat[1][0] * mat.fdMat[2][3] * mat.fdMat[3][1] -
						mat.fdMat[0][2] * mat.fdMat[1][1] * mat.fdMat[2][0] * mat.fdMat[3][3] -
						mat.fdMat[0][2] * mat.fdMat[1][3] * mat.fdMat[2][1] * mat.fdMat[3][0] -

						mat.fdMat[0][3] * mat.fdMat[1][0] * mat.fdMat[2][1] * mat.fdMat[3][2] -
						mat.fdMat[0][3] * mat.fdMat[1][1] * mat.fdMat[2][2] * mat.fdMat[3][0] -
						mat.fdMat[0][3] * mat.fdMat[1][2] * mat.fdMat[2][0] * mat.fdMat[3][1];
			cout << det << endl;
			if (det == 0) {
				throw "Matrix has no inverse";
			};
			
			fdMatrix m;
			m = mat;

			float inverseDet = 1 / det;
			mat[0][0] = ((m.fdMat[1][1] * m.fdMat[2][2] * m.fdMat[3][3] - //OK
				m.fdMat[1][1] * m.fdMat[2][3] * m.fdMat[3][2] - //OK
				m.fdMat[2][1] * m.fdMat[1][2] * m.fdMat[3][3] + //OK
				m.fdMat[2][1] * m.fdMat[1][3] * m.fdMat[3][2] + //OK
				m.fdMat[3][1] * m.fdMat[1][2] * m.fdMat[2][3] - //OK
				m.fdMat[3][1] * m.fdMat[1][3] * m.fdMat[2][2]) * inverseDet); //OK

			mat[1][0] = ((-(m.fdMat[1][0] * m.fdMat[2][2] * m.fdMat[3][3]) + //OK
				m.fdMat[1][0] * m.fdMat[2][3] * m.fdMat[3][2] +	//OK
				m.fdMat[2][0] * m.fdMat[1][2] * m.fdMat[3][3] - //OK
				m.fdMat[2][0] * m.fdMat[1][3] * m.fdMat[3][2] - //OK
				m.fdMat[3][0] * m.fdMat[1][2] * m.fdMat[2][3] + //OK
				m.fdMat[3][0] * m.fdMat[1][3] * m.fdMat[2][2]) * inverseDet); //OK

			mat[2][0] = ((m.fdMat[1][0] * m.fdMat[2][1] * m.fdMat[3][3] - //OK
				m.fdMat[1][0] * m.fdMat[2][3] * m.fdMat[3][1] - //OK
				m.fdMat[2][0] * m.fdMat[1][1] * m.fdMat[3][3] + //OK
				m.fdMat[2][0] * m.fdMat[1][3] * m.fdMat[3][1] + //OK
				m.fdMat[3][0] * m.fdMat[1][1] * m.fdMat[2][3] - //OK
				m.fdMat[3][0] * m.fdMat[1][3] * m.fdMat[2][1]) * inverseDet); //OK

			mat[3][0] = ((-(m.fdMat[1][0] * m.fdMat[2][1] * m.fdMat[3][2]) + //OK
				m.fdMat[1][0] * m.fdMat[2][2] * m.fdMat[3][1] + //OK
				m.fdMat[2][0] * m.fdMat[1][1] * m.fdMat[3][2] - //OK
				m.fdMat[2][0] * m.fdMat[1][2] * m.fdMat[3][1] - //OK
				m.fdMat[3][0] * m.fdMat[1][1] * m.fdMat[2][2] + //OK
				m.fdMat[3][0] * m.fdMat[1][2] * m.fdMat[2][1]) * inverseDet); //OK


			mat[0][1] = ((-(m.fdMat[0][1] * m.fdMat[2][2] * m.fdMat[3][3]) + //OK
				m.fdMat[0][1] * m.fdMat[2][3] * m.fdMat[3][2] + //OK
				m.fdMat[2][1] * m.fdMat[0][2] * m.fdMat[3][3] - //OK
				m.fdMat[2][1] * m.fdMat[0][3] * m.fdMat[3][2] - //OK
				m.fdMat[3][1] * m.fdMat[0][2] * m.fdMat[2][3] + //OK
				m.fdMat[3][1] * m.fdMat[0][3] * m.fdMat[2][2]) * inverseDet); //OK

			mat[1][1] = ((m.fdMat[0][0] * m.fdMat[2][2] * m.fdMat[3][3] - //OK
				m.fdMat[0][0] * m.fdMat[2][3] * m.fdMat[3][2] -	//OK
				m.fdMat[2][0] * m.fdMat[0][2] * m.fdMat[3][3] +	//OK
				m.fdMat[2][0] * m.fdMat[0][3] * m.fdMat[3][2] + //OK
				m.fdMat[3][0] * m.fdMat[0][2] * m.fdMat[2][3] - //OK
				m.fdMat[3][0] * m.fdMat[0][3] * m.fdMat[2][2]) * inverseDet); //OK

			mat[2][1] = ((-(m.fdMat[0][0] * m.fdMat[2][1] * m.fdMat[3][3]) + //OK
				m.fdMat[0][0] * m.fdMat[2][3] * m.fdMat[3][1] + //OK
				m.fdMat[2][0] * m.fdMat[0][2] * m.fdMat[3][3] - //OK
				m.fdMat[2][0] * m.fdMat[0][3] * m.fdMat[3][1] - //OK
				m.fdMat[3][0] * m.fdMat[0][2] * m.fdMat[2][3] + //OK
				m.fdMat[3][0] * m.fdMat[0][3] * m.fdMat[2][1]) * inverseDet); //OK

			mat[3][1] = ((m.fdMat[0][0] * m.fdMat[2][1] * m.fdMat[3][2] - //OK
				m.fdMat[0][0] * m.fdMat[2][2] * m.fdMat[3][1] - //OK
				m.fdMat[2][0] * m.fdMat[0][1] * m.fdMat[3][2] + //OK
				m.fdMat[2][0] * m.fdMat[0][2] * m.fdMat[3][1] + //OK
				m.fdMat[3][0] * m.fdMat[0][1] * m.fdMat[2][2] - //OK
				m.fdMat[3][0] * m.fdMat[0][2] * m.fdMat[2][1]) * inverseDet); //OK

			mat[0][2] = ((m.fdMat[0][1] * m.fdMat[1][2] * m.fdMat[3][3] - //OK
				m.fdMat[0][1] * m.fdMat[1][3] * m.fdMat[3][2] - //OK
				m.fdMat[1][1] * m.fdMat[0][2] * m.fdMat[3][3] + //OK
				m.fdMat[1][1] * m.fdMat[0][3] * m.fdMat[3][2] + //OK
				m.fdMat[3][1] * m.fdMat[0][2] * m.fdMat[1][3] - //OK
				m.fdMat[3][1] * m.fdMat[0][3] * m.fdMat[1][2]) * inverseDet); //OK

			mat[1][2] = ((-(m.fdMat[0][0] * m.fdMat[1][2] * m.fdMat[3][3]) + //OK
				m.fdMat[0][0] * m.fdMat[1][3] * m.fdMat[3][2] + //OK
				m.fdMat[1][0] * m.fdMat[0][2] * m.fdMat[3][3] - //OK
				m.fdMat[1][0] * m.fdMat[0][3] * m.fdMat[3][2] - //OK
				m.fdMat[3][0] * m.fdMat[0][2] * m.fdMat[1][3] + //OK
				m.fdMat[3][0] * m.fdMat[0][3] * m.fdMat[1][2]) * inverseDet); //OK

			mat[2][2] = ((m.fdMat[0][0] * m.fdMat[1][1] * m.fdMat[3][3] - //OK
				m.fdMat[0][0] * m.fdMat[1][3] * m.fdMat[3][1] - //OK
				m.fdMat[1][0] * m.fdMat[0][2] * m.fdMat[3][3] + //OK
				m.fdMat[1][0] * m.fdMat[0][3] * m.fdMat[3][1] + //OK
				m.fdMat[3][0] * m.fdMat[0][2] * m.fdMat[1][3] - //OK
				m.fdMat[3][0] * m.fdMat[0][3] * m.fdMat[1][1]) * inverseDet); //OK

			mat[3][2] = ((-(m.fdMat[0][0] * m.fdMat[1][1] * m.fdMat[3][2]) + //OK
				m.fdMat[0][0] * m.fdMat[1][2] * m.fdMat[3][1] + //OK
				m.fdMat[1][0] * m.fdMat[0][1] * m.fdMat[3][2] - //OK
				m.fdMat[1][0] * m.fdMat[0][2] * m.fdMat[3][1] - //OK
				m.fdMat[3][0] * m.fdMat[0][1] * m.fdMat[1][2] + //OK
				m.fdMat[3][0] * m.fdMat[0][2] * m.fdMat[1][1]) * inverseDet); //OK

			mat[0][3] = ((-(m.fdMat[0][1] * m.fdMat[1][2] * m.fdMat[2][3]) + //OK
				m.fdMat[0][1] * m.fdMat[1][3] * m.fdMat[2][2] +	//OK
				m.fdMat[1][1] * m.fdMat[0][2] * m.fdMat[2][3] - //OK
				m.fdMat[1][1] * m.fdMat[0][3] * m.fdMat[2][2] - //OK
				m.fdMat[2][1] * m.fdMat[0][2] * m.fdMat[1][3] + //OK
				m.fdMat[2][1] * m.fdMat[0][3] * m.fdMat[1][2]) * inverseDet); //OK

			mat[1][3] = ((m.fdMat[0][0] * m.fdMat[1][2] * m.fdMat[2][3] - //OK
				m.fdMat[0][0] * m.fdMat[1][3] * m.fdMat[2][2] - //OK
				m.fdMat[1][0] * m.fdMat[0][2] * m.fdMat[2][3] + //OK
				m.fdMat[1][0] * m.fdMat[0][3] * m.fdMat[2][2] + //OK
				m.fdMat[2][0] * m.fdMat[0][2] * m.fdMat[1][3] - //OK
				m.fdMat[2][0] * m.fdMat[0][3] * m.fdMat[1][2]) * inverseDet); //OK

			mat[2][3] = ((-(m.fdMat[0][0] * m.fdMat[1][1] * m.fdMat[2][3]) + //OK
				m.fdMat[0][0] * m.fdMat[1][3] * m.fdMat[2][1] + //OK	
				m.fdMat[1][0] * m.fdMat[0][1] * m.fdMat[2][3] - //OK
				m.fdMat[1][0] * m.fdMat[0][3] * m.fdMat[2][1] - //OK
				m.fdMat[2][0] * m.fdMat[0][1] * m.fdMat[1][3] + //OK
				m.fdMat[2][0] * m.fdMat[0][3] * m.fdMat[1][1]) * inverseDet); //OK

			mat[3][3] = ((m.fdMat[0][0] * m.fdMat[1][1] * m.fdMat[2][2] - //OK
				m.fdMat[0][0] * m.fdMat[1][2] * m.fdMat[2][1] - //OK
				m.fdMat[1][0] * m.fdMat[0][1] * m.fdMat[2][2] + //OK
				m.fdMat[1][0] * m.fdMat[0][2] * m.fdMat[2][1] + //OK
				m.fdMat[2][0] * m.fdMat[0][1] * m.fdMat[1][2] - //OK
				m.fdMat[2][0] * m.fdMat[0][2] * m.fdMat[1][1]) * inverseDet); //OK
				return mat;
		}
		//Multiplies matrix opperator override
		fdMatrix& fdMatrix::operator*(fdMatrix& mat)
		{
			fdMatrix * mult;
			mult = new fdMatrix;
			float temp = 0;
			int a, b, c;

			for (a = 0; a < 4; a++)
			{
				for (b = 0; b < 4; b++)
				{
					for (c = 0; c < 4; c++)
					{
						temp += get_Element(b, c) * mat.get_Element(c, a);
					}
					mult->fdMat[b][a] = temp;
					temp = 0;
				}
			}
			return *mult;
		}
		//Equals matrix opperator override
		fdMatrix& fdMatrix::operator=(const fdMatrix& mat)
		{
			for (int i = 0; i <= 3; i++)
			{
				for (int k = 0; k <= 3; k++)
				{
					fdMat[i][k] = mat.fdMat[i][k];
				}
			}

			return *this;
		}
		//[] opperator override
		float* fdMatrix::operator[](int val)
		{
			return fdMat[val];
		}

};