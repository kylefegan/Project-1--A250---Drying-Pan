#include "Matrix.h"

//Default Constructor
Matrix::Matrix()
{
	verts = 0;
	capacity = CAPACITY;
	ptrToVerts = new string[capacity]();

	twoD = new int*[capacity]();
	for (int i = 0; i < capacity; ++i)
		twoD[i] = new int[capacity]();
}

//Overloaded Constructor
Matrix::Matrix(int vertices)
{
	verts = vertices;
	capacity = vertices*2;
	ptrToVerts = new string[capacity]();

	twoD = new int*[capacity]();
	for (int i = 0; i < capacity; ++i)
		twoD[i] = new int[capacity]();
}

//copy constructor
Matrix::Matrix(const Matrix& otherMatrix)
{
	verts = otherMatrix.verts;
	capacity = otherMatrix.capacity;
	ptrToVerts = new string[capacity]();

	twoD = new int*[capacity]();
	for (int i = 0; i < capacity; ++i)
		twoD[i] = new int[capacity]();
}

//move constructor
Matrix::Matrix(Matrix&& otherMatrix)
{
	verts = otherMatrix.verts;
	capacity = otherMatrix.capacity;
	ptrToVerts = otherMatrix.ptrToVerts;
	twoD = otherMatrix.twoD;

	otherMatrix.verts = 0;
	otherMatrix.capacity = 0;
	otherMatrix.ptrToVerts = nullptr;
	otherMatrix.twoD = nullptr;
}

//CreateMatrix()
void Matrix::createMatrix(const vector<vector<string>>& blueprint)
{
	int size = blueprint.size();
	for (int i = 0; i < size; ++i)
	{
		ptrToVerts[i] = blueprint[i][0];
	}

	int iSize;
	int count;
	for (int i = 0; i < size; ++i)
	{
		iSize = blueprint[i].size();
		for (int j = 1; j < iSize; ++j)
		{
			count = 0;
			while (blueprint[i][j] != ptrToVerts[count])
			{
				++count;
			}
			twoD[i][count] = 1;
		}
	}
}

//insertion operator
ostream & operator<<(ostream & out, const Matrix & object)
{
	for (int i = 0; i < object.verts; i++)
	{
		out << object.ptrToVerts[i] << " ";
	}
	out << endl;
	for (int i = 0; i < object.verts; i++)
	{
		for (int j = 0; j < object.verts; j++)
		{
			out << object.twoD[j][i] << " ";
		}
		out << endl;
	}
	return out;
}

//destroy matrix & destructor
void Matrix::destroyMatrix()
{
	if (capacity > 0)
	{
		for (int i = 0; i < verts; i++)
			delete twoD[i];
		delete[] twoD;
		twoD = nullptr;
		delete[] ptrToVerts;
		ptrToVerts = nullptr;
		capacity = 0;
		verts = 0;
	}
}

Matrix::~Matrix()
{
	destroyMatrix();
}

//assignment operator

//move assignment operator

//insert vert

//is empty

//get verts

//empty graph
