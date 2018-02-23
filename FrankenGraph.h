
#ifndef FRANKENGRAPH_H
#define FRANKENGRAPH_H

#include<iostream>
#include <string>		//Need to include for NULL	
#include <vector>
#include "AnyList.h"
using namespace std;

class FrankenGraph
{
public:
	//default constructor
	FrankenGraph();

	//overloaded constructor
	FrankenGraph(int vectorSize);

	//creates graph
	void createGraph(const vector<vector<string>>& blueprint);

	//destructor
	//~FrankenGraph();

private:
	AnyList **ptrToSucc;
	string *ptrToVerts;
	int verts;
	int capacity;
};

#endif

