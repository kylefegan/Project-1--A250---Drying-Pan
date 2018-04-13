/********************************************

	Radix Sort
	Running time: O(n * k)

********************************************/

#include <iostream>
#include <string>
#include <string>

using namespace std;

const int CAP = 20;

void print(const int *a, int numOfElements);

int main()
{
	int digits = 3;
	int numOfElements = 15;
	
	int *a1 = new int[CAP] {789, 456, 123, 741, 852, 963, 321, 654, 987, 147, 258, 369, 159, 753, 111};
	int *a2 = new int[CAP];

	cout << "Start:  ";
	print(a1,numOfElements);
	cout << endl;

	/***********************************************************************************************************/
	// Your code ONLY in this section...

	// PRINT FROM HERE....
	/*
		Manning, Tristan

		CS A200
		April 12, 2018

		Lab 5
	*/
	cout << endl;
	int index = 0;
	int digit = 0;
	int myNum = 10;
	for (int i = 0; i < digits; ++i)
	{
		while (index < numOfElements)		//stops when array is full
		{
			for (int i = 0; i < numOfElements; ++i)
			{
				if (a1[i] % myNum == digit)
				{
					a2[index] = a1[i];
					++index;
				}
			}
			++digit;
		}
		myNum *= 10;		//cycles to the next digit
		index = 0;
		digit = 0;

		cout << "Pass " + to_string(i + 1) + ": ";
		print(a2, numOfElements);
		cout << endl;

		int * temp = a1;
		a1 = a2;
		a2 = temp;
	}
	
	
	// END PRINTING HERE... 

	/***********************************************************************************************************/

	cout << endl << endl;
	system("Pause");
	return 0;
}

void print(const int *a, int numOfElements)
{
	for (int i = 0; i < numOfElements; ++i)
		cout << a[i] << " ";
}
