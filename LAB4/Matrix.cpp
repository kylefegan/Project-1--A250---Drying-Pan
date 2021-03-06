/*
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre
	Amarith, David

	CS A200
	March 11, 2018

	Lab 4
*/

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

	for (int i = 0; i < verts; ++i)
	{
		ptrToVerts[i] = otherMatrix.ptrToVerts[i];

		for (int j = 0; j < verts; ++j)
		{
			twoD[i][j] = otherMatrix.twoD[i][j];
		}
	}
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
	if (object.verts > 0)
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
	}
	else cerr << "Error: Graph is empty." << endl;
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
Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
	if (&otherMatrix != this)
	{
		if (capacity != otherMatrix.capacity)
		{
			delete[] ptrToVerts;
			ptrToVerts = new string[otherMatrix.capacity];

			for (int i = 0; i < verts; i++)
				delete twoD[i];
			delete[] twoD;

			twoD = new int*[otherMatrix.capacity]();
			for (int i = 0; i < otherMatrix.capacity; ++i)
				twoD[i] = new int[otherMatrix.capacity]();

			capacity = otherMatrix.capacity;
		}

		verts = otherMatrix.verts;

		//start copying
		for (int i = 0; i < verts; ++i)
		{
			ptrToVerts[i] = otherMatrix.ptrToVerts[i];

			for (int j = 0; j < verts; ++j)
			{
				twoD[i][j] = otherMatrix.twoD[i][j];
			}
		}

	}
	else
	{
		cerr << "Attempted assignment to itself.";
	}

	return *this;
}

//move assignment operator
Matrix& Matrix::operator=(Matrix&& otherMatrix)
{
	if (this != &otherMatrix)
	{
		destroyMatrix();

		verts = otherMatrix.verts;
		capacity = otherMatrix.capacity;
		ptrToVerts = otherMatrix.ptrToVerts;
		twoD = otherMatrix.twoD;

		otherMatrix.verts = 0;
		otherMatrix.capacity = 0;
		otherMatrix.ptrToVerts = nullptr;
		otherMatrix.twoD = nullptr;
	}
	else
		cerr << "Attempted assignment of itself." << endl;

	return *this;
}

//insert vert
void Matrix::insertVert(const string& newVert, const vector<string>& pred, const vector<string>& succ)
{
	int predSize = static_cast<int>(pred.size());
	int succSize = static_cast<int>(succ.size());
	int count = 0;
	if (verts < capacity)
	{
		ptrToVerts[verts] = newVert;

		//iterate horizontally to add newVert as successor
		while (count < predSize)
		{
			for (int i = 0; i < verts; i++)
			{
				if (ptrToVerts[i] == pred[count])
					twoD[i][verts] = 1;
			}
			++count;
		}
		count = 0;

		//iterate vertically to add to newVert's successors
		while (count < succSize)
		{
			for (int i = 0; i < verts; i++)
			{
				if (ptrToVerts[i] == succ[count])
					twoD[verts][i] = 1;
			}
			++count;
		}
		++verts;
	}
	else
	{
		cerr << "Attempted to exceed capacity of array." << endl;
	}
}

//empty graph
void Matrix::emptyGraph()
{
	for (int i = 0; i < verts; i++)
	{
		ptrToVerts[i] = "";
		for (int j = 0; j < verts; j++)
		{
			twoD[j][i] = 0;
		}
	}
	verts = 0;
}
