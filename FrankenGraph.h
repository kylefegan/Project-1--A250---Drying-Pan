
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
	
	//copy contructor
	Graph::Graph(const Graph& otherGraph);

	//move constructor
	Graph(Graph&& otherGraph);

	//assignment operator
	Graph& operator =(const Graph& otherGraph);

	//move assignment operator
	Graph& operator =(Graph&& otherGraph);

	//creates graph
	void createGraph(const vector<vector<string>>& blueprint);

	//destroys Graph
	void destroyGraph();
	
	//destructor
	//~FrankenGraph();

private:
	AnyList **ptrToSucc;
	string *ptrToVerts;
	int verts;
	int capacity;
};

#endif

