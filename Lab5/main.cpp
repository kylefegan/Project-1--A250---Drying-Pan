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
	print(a1, numOfElements);
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
	int myNum = 1;
	int count = 0;
	for (int i = 0; i < digits; ++i)					// O-notation = O(k) where k is the number of digits. For loop will 
	{													// iterate k times because "digits" is equal to the number of digits.
		while (index < (numOfElements - 1))				// O-notation = O(10) because the loop checks if the array is full. Worst case
		{												// is one element in the array having a digit 9 and having to iterate until the digit
														// we're checking equals 9.
			for (int j = 0; j < numOfElements; ++j)		// O-notation = O(n) where n is the number of elements in the array. 
			{											// For loop goes through each element and checks if the digit we're looking at equals
				if ((a1[j] / myNum) % 10 == digit)		// the digit we're checking for
				{
					a2[index] = a1[j];
					++index;
				}
			}
			++digit;
		}
		myNum *= 10;		// cycles to the next digit
		index = 0;			// reset variables
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
