
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include <string>		//Need to include for NULL	
#include <vector>
#include "AnyList.h"
using namespace std;

class Graph
{
	friend ostream& operator<<(ostream& out, const Graph& object);
public:
	//default constructor
	Graph();

	//overloaded constructor
	Graph(int vectorSize);

	//copy contructor
	Graph(const Graph& otherGraph);

	//move constructor
	Graph(Graph&& otherGraph);

	//assignment operator
	Graph& operator =(const Graph& otherGraph);

	//move assignment operator
	Graph& operator =(Graph&& otherGraph);
	
	//getVets
	int getVerts() const;

	//is empty
	bool isEmpty()const;

	//returns address of object
	const Graph* addressGraph()const;

	//address of ptrToVerts
	AnyList** addressVerts() const;

	//address of ptrToSucc
	string* addressSucc() const;

	//creates graph
	void createGraph(const vector<vector<string>>& blueprint);

	//void insert cert
	void insertVert(const string& vert, const vector<string>& pred, const vector<string>& succ);

	//empty Graph
	void emptyGraph();

	//destroys Graph
	void destroyGraph();

	//destructor
	~Graph();

private:
	AnyList **ptrToSucc;
	string *ptrToVerts;
	int verts;
	int capacity;
};

#endif
