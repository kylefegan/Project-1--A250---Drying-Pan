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


	Matrix m = Matrix(static_cast<int>(data.size()));
	m.createMatrix(data);
	cout << m;

	system("Pause");
	return 0;
}