#include "FrankenGraph.h"

//Default Constructor
FrankenGraph::FrankenGraph()
{
	verts = 0;
	capacity = 0;
	ptrToVerts = nullptr;
	ptrToSucc = nullptr;
}

//Overloaded Constructor
FrankenGraph::FrankenGraph(int vectorSize)
{
	verts = vectorSize;
	capacity = vectorSize * 2;
	ptrToVerts = new string[capacity];
	ptrToSucc = new AnyList* [capacity];
}

//CreateGraph()
void FrankenGraph::createGraph(const vector<vector<string>>& blueprint)
{
	int count = 0;
	for (auto i : blueprint)
	{
		ptrToVerts[count] = i[0];

		int isize = i.size();
		AnyList successors;
		for (int j = 0; j < isize; j++)
		{
			successors.insertFront(i[j]);
		}
		ptrToSucc[count] = &successors;
		successors.print();
		count++;
	}
}
//copy constructor
Graph::Graph(const Graph& otherGraph)
{
	capacity = otherGraph.capacity;
	verts = otherGraph.verts;

	int count = 0;
	while (otherGraph.ptrToSucc[count])
	{
		ptrToVerts[count] = otherGraph.ptrToVerts[count];
		ptrToSucc[count] = otherGraph.ptrToSucc[count];
		count++;
	}
}
//move constructor
Graph::Graph(Graph&& otherGraph)
{
	verts = otherGraph.verts;
	capacity = otherGraph.capacity;
	ptrToSucc = otherGraph.ptrToSucc;
	ptrToVerts = otherGraph.ptrToVerts;

	otherGraph.verts = 0;
	otherGraph.capacity = 0;
	delete[] otherGraph.ptrToSucc;
	otherGraph.ptrToSucc = nullptr;
	delete[] otherGraph.ptrToVerts;
	otherGraph.ptrToVerts = nullptr;
}
//assignment operator
Graph& Graph::operator=(const Graph& otherGraph)
{
	if (&otherGraph != this)
	{
		//if the array we are passing has a different
		//  capacity from the calling object,
		//  then we need to create a new array
		if (capacity != otherGraph.capacity)
		{
			//deallocate the memory used by 
			//  the calling object and
			//  re-create the object so that 
			//  it has the same capacity
			delete[] ptrToSucc;
			ptrToSucc = new AnyList*[otherGraph.capacity];
			delete[] ptrToVerts;
			ptrToVerts = new string[otherGraph.capacity];
			//update capacity
			capacity = otherGraph.capacity;
			verts = otherGraph.verts;
		}

		//update number of elements	
		capacity = otherGraph.capacity;

		// start copying
		int count = 0;
		while(otherGraph.ptrToSucc[count])
		{
			ptrToVerts[count] = otherGraph.ptrToVerts[count];
			ptrToSucc[count] = otherGraph.ptrToSucc[count];
			count++;
		}
	}
	else
	{
		cerr << "Attempted assignment to itself.";
	}

	return *this;
}
//move assignment operator
Graph& Graph::operator=(Graph&& otherGraph)
{	
	if (this != &otherGraph)
	{
		verts = otherGraph.verts;
		capacity = otherGraph.capacity;
		otherGraph.capacity = 0;
		otherGraph.verts = 0;
		//if we are just moving pointers we will have to delete the other array
		delete[] ptrToVerts;
		ptrToVerts = otherGraph.ptrToVerts;
		otherGraph.ptrToVerts = nullptr;

		delete[] ptrToSucc;
		ptrToSucc = otherGraph.ptrToSucc;
		otherGraph.ptrToSucc = nullptr;
	}
	else
		cerr << "Attempted assignment of itself." << endl;

	return *this;
}
//destructroy graph
void Graph::destroyGraph()
{
	//since the destructor would call destroyGraph
	//if we call destroy graph before this and dont properly 
	//delete the object the destructor will call this function causing an error
	if (capacity > 0)
	{
		int count = 0;
		while (ptrToSucc[count])
		{
			ptrToSucc[count]->destroyList();
			count++;
		}
		delete[] ptrToSucc;
		ptrToSucc = nullptr;
		delete[] ptrToVerts;
		ptrToVerts = nullptr;
		capacity = 0;
		verts = 0;
	}
	else
		cerr << "List is already empty" << endl;
}
//destructor
Graph::~Graph()
{
	destroyGraph();
}
int main(
{
	vector<vector<string>> data =
	{
		{"A", "B", "E"},
		{"B", "C", "D"},
		{"C", "D"},
		{"D"},
		{"E", "D"}
	};

	FrankenGraph g = FrankenGraph(data.size());
	g.createGraph(data);

	
	system("Pause");
	return 0;
}
