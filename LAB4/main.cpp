/*
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre
	Amarith, David

	CS A200
	March 11, 2018

	Lab 4
*/

#include"Matrix.h"
#include <utility>

int main()
{
	vector<vector<string>> data =
	{
		{ "A", "B", "F" },
		{ "B", "C", "D","F" },
		{ "C", "E" },
		{ "D" },
		{ "E", "D", "F" },
		{ "F", "D" },
	};

	vector<vector<string>> data2 =
	{
		{ "A", "C", "F" },
		{ "B", "C", "D","F" },
		{ "C", "D" },
		{ "D" },
		{ "D", "F" },
		{ "F", "D" },
	};


	Matrix m = Matrix(static_cast<int>(data.size()));
	m.createMatrix(data);
	cout << m << endl;

	Matrix n = Matrix(m);
	cout << n << endl;

	Matrix o = Matrix(static_cast<int>(data2.size()));
	o.createMatrix(data2);
	cout << o << endl;

	n = o;
	cout << n << endl;

	n = move(m);
	cout << n << endl;

	n.insertVert("Q", { "A", "B" }, { "D", "F" });
	cout << n << endl;

	n.emptyGraph();
	cout << n << endl;

	system("Pause");
	return 0;
}
