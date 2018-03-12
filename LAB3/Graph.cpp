#include "Graph.h"
const int CAPACITY = 10;
//Default Constructor
Graph::Graph()
{
	verts = 0;
	capacity = CAPACITY;
	ptrToVerts = new string[capacity]();
	ptrToSucc = new AnyList*[capacity]();
}
ostream& operator<<(ostream& out, const Graph& object)
{
	if (object.verts > 0)
	{
		for (int i = 0; i < object.verts; i++)
		{
			out << object.ptrToVerts[i];
			cout << *object.ptrToSucc[i];
		}
	}
	else
		cerr << "Graph is empty" << endl;
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
string* Graph::addressVerts() const
{
	return ptrToVerts;
}

//address of ptrToSucc
 AnyList** Graph::addressSucc() const
{
	return ptrToSucc;
}
 const Graph* Graph::addressGraph() const
 {
	 return this;
 }
//insert vert
void Graph::insertVert(const string& newVert, const vector<string>& pred, const vector<string>& succ)
{
	if (verts < capacity)
	{
		int predLength = static_cast<int>(pred.size());
		int succLength = static_cast<int>(succ.size());
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
		++verts;
	}
	else
	{
		cerr << "Attempted to exceed capacity in DArray."<<endl;
		exit(0);
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
	if (verts > 0)
	{
		for (int i = 0; i < verts; i++)
		{
			ptrToVerts[i] = "";
			ptrToSucc[i]->destroyList();
		}
	}
	else
		cout << "Graph is already empty!" << endl;
}
//destructroy graph
void Graph::destroyGraph()
{
	if (verts > 0)
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
