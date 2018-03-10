#include "Graph.h"

//Default Constructor
Graph::Graph()
{
	verts = 0;
	capacity = 0;
	ptrToVerts = nullptr;
	ptrToSucc = nullptr;
}
ostream& operator<<(ostream& out, const Graph& object)
{
	for (int i = 0; i < object.verts; i++)
	{
		out << object.ptrToVerts[i];
		cout << *object.ptrToSucc[i];
	}
	return out;
}
//Overloaded Constructor
Graph::Graph(int vectorSize)
{
	verts = vectorSize;
	capacity = vectorSize * 2;
	ptrToVerts = new string[capacity]();
	ptrToSucc = new AnyList*[capacity]();
}
//copy constructor
Graph::Graph(const Graph& otherGraph)
{
	capacity = otherGraph.capacity;
	verts = otherGraph.verts;
	ptrToVerts = new string[capacity]();
	ptrToSucc = new AnyList*[capacity]();
	for (int i = 0; i < verts; i++)
	{
		ptrToVerts[i] = otherGraph.ptrToVerts[i];
		ptrToSucc[i] = otherGraph.ptrToSucc[i];
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
	otherGraph.ptrToSucc = nullptr;
	otherGraph.ptrToVerts = nullptr;
}
//CreateGraph()
void Graph::createGraph(const vector<vector<string>>& blueprint)
{
	int count = 0;
	for (auto i : blueprint)
	{
		ptrToVerts[count] = i[0];

		int isize = static_cast<int>(i.size());
		AnyList *successors;
		successors = new AnyList;
		for (int j = 1; j < isize; j++)
		{
			successors->insertFront(i[j]);
		}
		ptrToSucc[count] = successors;
		count++;
	}
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
		for (int i = 0; i < verts; i++)
		{
			ptrToVerts[i] = otherGraph.ptrToVerts[i];
			ptrToSucc[i] = otherGraph.ptrToSucc[i];
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
		destroyGraph();
		verts = otherGraph.verts;
		capacity = otherGraph.capacity;
		otherGraph.capacity = 0;
		otherGraph.verts = 0;
		//if we are just moving pointers we will have to delete the other array
		ptrToVerts = new string[capacity]();
		ptrToVerts = otherGraph.ptrToVerts;
		otherGraph.ptrToVerts = nullptr;

		ptrToSucc = new AnyList*[capacity]();
		ptrToSucc = otherGraph.ptrToSucc;
		otherGraph.ptrToSucc = nullptr;
	}
	else
		cerr << "Attempted assignment of itself." << endl;

	return *this;
}
//address of ptrToVerts
AnyList** Graph::addressVerts() const
{
	return ptrToSucc;
}

//address of ptrToSucc
 string* Graph::addressSucc() const
{
	return ptrToVerts;
}
 const Graph* Graph::addressGraph() const
 {
	 return this;
 }
//insert vert
void Graph::insertVert(const string& newVert, const vector<string>& pred, const vector<string>& succ)
{
	int predLength = static_cast<int>(pred.size());
	int succLength = static_cast<int>(succ.size());
	verts++;
	ptrToVerts[verts] = newVert;
	AnyList *newSucc;
	newSucc = new AnyList;
	for (int i = 0; i < succLength; i++)
	{
		newSucc->insertFront(succ[i]);
	}
	ptrToSucc[verts] = newSucc;
	for (int i = 0; i < predLength; i++)
	{
		for (int j = 0; j < verts; j++)
		{
			if (pred[i] == ptrToVerts[j])
				ptrToSucc[j]->insertFront(newVert);
		}
	}
}

//is empty
bool Graph::isEmpty() const
{
	return capacity == 0;
}

//get verts
int Graph::getVerts() const
{
	return verts;
}

//empty graph
void Graph::emptyGraph()
{
	for (int i = 0; i < verts; i++)
	{
		ptrToVerts[i] = "";
		ptrToSucc[i]->destroyList();
	}
}
//destructroy graph
void Graph::destroyGraph()
{
	//since the destructor would call destroyGraph
	//if we call destroy graph before this and dont properly 
	//delete the object the destructor will call this function causing an error
	if (capacity > 0)
	{
		for(int i = 0; i < verts; i++)
			ptrToSucc[i]->destroyList();
		delete[] ptrToSucc;
		ptrToSucc = nullptr;
		delete[] ptrToVerts;
		ptrToVerts = nullptr;
		capacity = 0;
		verts = 0;
	}
}
//destructor
Graph::~Graph()
{
	destroyGraph();
}
