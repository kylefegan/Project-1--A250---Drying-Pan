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

int main()
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
