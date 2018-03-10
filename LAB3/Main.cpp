#include"Graph.h"
#include <utility>
#include"AnyList.h"
void test_copyConstructor()
{
	vector<vector<string>> data =
	{
		{ "A", "B", "F" },
		{ "B", "C", "D","F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "G" },
		{ "G" },

	};
	cout << "/*********************************************************/\n";
	cout << "     TEST: COPY CONSTRUCTOR" << endl;
	cout << "/*********************************************************/\n";

	Graph g = Graph(static_cast<int>(data.size()));
	g.createGraph(data);
	if (g.isEmpty()) cerr << "\nGraph2: (Empty)";
	else cout << "Original Graph:\n" << g << endl;

	Graph g2(g);
	cout << "\nCalling Copy Constructor:" << endl;
	if (g2.isEmpty()) cerr << "\nGraph2: (Empty)";
	else cout << g2 << endl;

	if (!g.isEmpty() && !g2.isEmpty())
	{
		cout << "\n\n=>Check address of Graphs";
		cout << "\nGraph: 1" << g.addressGraph();
		cout << "\nGraph2: " << g2.addressGraph();
		cout << "\n\n=> Check address of succesor array (should be different)...";
		cout << "\nGraph1: " << g.addressSucc();
		cout << "\nGraph2: " << g2.addressSucc();
		cout << "\n\n=> Check address of vertex array (should be different)...";
		cout << "\nGraph1: " << g.addressVerts();
		cout << "\nGraph2: " << g2.addressVerts();
		cout << "\n\n=> Check number of vertex array (should be the same)...";
		cout << "\nGraph1: " << g.getVerts();
		cout << "\nGraph2: " << g2.getVerts();
	}

}


void test_moveConstructor()
{
	vector<vector<string>> data2 =
	{
		{ "A", "B", "F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "E" },
	};
	cout << "/*********************************************************/\n";
	cout << "     TEST: MOVE CONSTRUCTOR" << endl;
	cout << "/*********************************************************/\n";

	Graph g = Graph(static_cast<int>(data2.size()));
	g.createGraph(data2);
	if (g.isEmpty()) cerr << "\nGraph2: (Empty)";
	else cout << "Original Graph:\n" <<g << endl;

	Graph g2 = move(g);
	cout << "\nCalling Move Constructor:" << endl;
	if (g2.isEmpty()) cerr << "\nGraph2: (Empty)";
	else cout << g2 << endl;

	if (g2.isEmpty()) cerr << "\n Graph2: empty";
	else
	{
		cout << "\n\n=>Check address of Graphs";
		cout << "\nGraph1: " << g.addressGraph();
		cout << "\nGraph2: " << g2.addressGraph();
		cout << "\n\n=> Check address of succesor array (should be different)...";
		cout << "\nGraph1: " << g.addressSucc();
		cout << "\nGraph2: " << g2.addressSucc();
		cout << "\n\n=> Check address of vertex array (should be different)...";
		cout << "\nGraph1: " << g.addressVerts();
		cout << "\nGraph2: " << g2.addressVerts();
		cout << "\n\n=> Check number of vertex in array (should be the same)...";
		cout << "\nGraph1: " << g.getVerts();
		cout << "\nGraph2: " << g2.getVerts();
	}

}
void test_assignmentOperator()
{
	vector<vector<string>> data2 =
	{
		{ "A", "B", "F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "E" },
	};
	vector<vector<string>> data3 =
	{
		{ "B", "C", "F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "B" },
	};
	Graph g = Graph(static_cast<int>(data2.size()));
	Graph g2 = Graph(static_cast<int>(data3.size()));
	g.createGraph(data2);
	g2.createGraph(data3);
	cout << "/*********************************************************/\n";
	cout << "     TEST: ASSIGNMENT OPERATOR" << endl;
	cout << "/*********************************************************/\n";

	cout << "\nGraph1:\n" << g;
	cout << "\nGraph2:\n" << g2;

	cout << "\n=> Use overloaded assignment operator to copy Graph1 into Graph2...";
	g2 = g;
	if (g2.isEmpty()) cerr << "\nGraph2: (empty)";
	else cout << "\nGraph2:\n" << g2;

	cout << "\n\n=>Check address of Graphs (should be different)...";
	cout << "\nGraph1: " << g.addressGraph();
	cout << "\nGraph2: " << g2.addressGraph();
	if (!g.isEmpty() && !g2.isEmpty())
	{
		cout << "\n\n=> Check address of succesor array (should be different)...";
		cout << "\nGraph1: " << g.addressSucc();
		cout << "\nGraph2: " << g2.addressSucc();
		cout << "\n\n=> Check address of vertex array (should be different)...";
		cout << "\nGraph1: " << g.addressVerts();
		cout << "\nGraph2: " << g2.addressVerts();
		cout << "\n\n=> Check number of vertex in array (should be the same)...";
		cout << "\nGraph1: " << g.getVerts();
		cout << "\nGraph2: " << g2.getVerts();
	}
}
void test_moveAssignment()
{
	vector<vector<string>> data2 =
	{
		{ "A", "B", "F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "E" },
	};
	vector<vector<string>> data3 =
	{
		{ "B", "C", "F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "B" },
	};

	Graph g = Graph(static_cast<int>(data2.size()));
	Graph g2 = Graph(static_cast<int>(data3.size()));
	g.createGraph(data2);
	g2.createGraph(data3);

	cout << "/*********************************************************/\n";
	cout << "     TEST: MOVE ASSIGNMENT OPERATOR" << endl;
	cout << "/*********************************************************/\n";

	cout << "\nGraph1:\n" << g;
	cout << "\nGraph2:\n" << g2;

	cout << "\n=> Use overloaded assignment operator to copy Graph1 into Graph2...";
	g2 = move(g);
	if (g2.isEmpty()) cerr << "\nGraph2: (empty)";
	else cout << "\nGraph2:\n" << g2;

	cout << "\n\n=>Check address of Graphs (should be different)...";
	cout << "\nGraph1: " << g.addressGraph();
	cout << "\nGraph2: " << g2.addressGraph();

	if (!g2.isEmpty())
	{
		cout << "\n\n=> Check address of succesor array (should be different)...";
		cout << "\nGraph1: " << g.addressSucc();
		cout << "\nGraph2: " << g2.addressSucc();
		cout << "\n\n=> Check address of vertex array (should be different)...";
		cout << "\nGraph1: " << g.addressVerts();
		cout << "\nGraph2: " << g2.addressVerts();
		cout << "\n\n=> Check number of vertex in array (should be the same)...";
		cout << "\nGraph1: " << g.getVerts();
		cout << "\nGraph2: " << g2.getVerts();
	}
	cout << endl;
}
void test_insertVertex()
{
	vector<vector<string>> data3 =
	{
		{ "B", "C", "F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "B" },
	};
	vector<string> pred = { "B","C" };
	vector<string> succ = { "E", "G" };
	string newVert = "H";
	Graph g = Graph(static_cast<int>(data3.size()));
	g.createGraph(data3);

	cout << "/*********************************************************/\n";
	cout << "     TEST: INSERT VERTEX" << endl;
	cout << "/*********************************************************/\n";
	cout << "\nGraph1:\n" << g;
	cout << "\nNew Graph" << endl;
	g.insertVert(newVert, pred, succ);
	cout << g << endl;

}
void test_emptyGraph()
{
	vector<vector<string>> data3 =
	{
		{ "B", "C", "F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "B" },
	};
	Graph g = Graph(static_cast<int>(data3.size()));
	g.createGraph(data3);
	cout << "/*********************************************************/\n";
	cout << "     TEST: Empty GRAPH" << endl;
	cout << "/*********************************************************/\n";
	cout << "\nGraph1:\n" << g;
	g.emptyGraph();
	if (!g.isEmpty())
	{
		cout << "This is the new Graph: " << endl;
		cout << g << endl;
		cout << "\n\n=> Check address of succesor array (should not be 0)...";
		cout << "\nGraph1: " << g.addressSucc();
		cout << "\n\n=> Check address of vertex array (should not be 0)...";
		cout << "\nGraph1: " << g.addressVerts();
		cout << "\n\n=> Check number of vertex in array (should not be 0)...";
		cout << "\nGraph1: " << g.getVerts() << endl;
	}
	else
		cout << "Empty Graph didn't work" << endl;
}

void test_destroyGraph()
{
	vector<vector<string>> data3 =
	{
		{ "B", "C", "F" },
		{ "C", "E" },
		{ "D", "G" },
		{ "E", "D", "F" },
		{ "F", "B" },
	};
	Graph g = Graph(static_cast<int>(data3.size()));
	g.createGraph(data3);
	cout << "/*********************************************************/\n";
	cout << "     TEST: DESTROY GRAPH" << endl;
	cout << "/*********************************************************/\n";
	cout << "\nGraph1:\n" << g;
	g.destroyGraph();
	if (g.isEmpty())
	{
		cout << "\nDeleted Graph succesfully" << endl;
		cout << "\n\n=> Check address of succesor array (should 0)...";
		cout << "\nGraph1: " << g.addressSucc();
		cout << "\n\n=> Check address of vertex array (should 0)...";
		cout << "\nGraph1: " << g.addressVerts();
		cout << "\n\n=> Check number of vertex in array (should 0)...";
		cout << "\nGraph1: " << g.getVerts() << endl;
	}
	else cout << "Destroy graph did not work" << endl;
}
int main()
{

	
	//test_copyConstructor();
	//test_moveConstructor();
	//test_assignmentOperator();
	//test_moveAssignment();
	//test_insertVertex();
	//test_destroyGraph();
	test_emptyGraph();

	cout << "/*********************************************************/\n";
	cout << "     TEST: DESTROY GRAPH" << endl;
	cout << "/*********************************************************/\n";

	
	system("Pause");
	return 0;
}
