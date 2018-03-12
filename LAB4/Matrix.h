/*
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre
	Amarith, David

	CS A200
	March 11, 2018

	Lab 4
*/

#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include <string>
#include <vector>
using namespace std;

const int CAPACITY = 20;

class Matrix
{
	//overloaded insertion
	friend ostream& operator<<(ostream& out, const Matrix& object);
public:
	//default constructor
	Matrix();

	//overloaded constructor
	Matrix(int vertices);

	//copy contructor
	Matrix(const Matrix& otherMatrix);

	//move constructor
	Matrix(Matrix&& otherMatrix);

	//create matrix
	void createMatrix(const vector<vector<string>>& blueprint);

	//destroy matrix
	void destroyMatrix();

	//destructor
	~Matrix();
	
	//assignment operator
	Matrix& operator=(const Matrix&);

	//move assignement operator
	Matrix& operator=(Matrix&& otherMatrix);
	
	//empty graph
	void emptyGraph();

	//insert vertex
	void insertVert(const string& newVert, const vector<string>& pred, const vector<string>& succ);

private:
	int **twoD;
	string *ptrToVerts;
	int verts;
	int capacity;
};

#endif
