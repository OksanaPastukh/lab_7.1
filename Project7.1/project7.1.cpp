// Lab_7_1.cpp
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** z, const int rowCount, const int colCount, const int Low,const int High);
void Print(int** z, const int rowCount, const int colCount);
void Sort(int** z, const int rowCount, const int colCount);
void Change(int** z,  const int rowCount, const int col1, const int col2);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 18;
	int High = 74;
	int rowCount = 9;
	int colCount = 6;
	int** z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		z[i] = new int[colCount];
	Create(z, rowCount, colCount, Low, High);
	Print(z, rowCount, colCount);
	Sort(z, rowCount, colCount);
	Print(z, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(z, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(z, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] z[i];
	delete[] z;
	return 0;
}
void Create(int** z, const int rowCount, const int colCount, const int Low,const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			z[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** z, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << z[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** z, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount - 1; j0++)
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
			if ((z[0][j1] > z[0][j1 + 1])
				||
				(z[0][j1] == z[0][j1 + 1] &&
					z[1][j1] < z[1][j1 + 1])
				||
				(z[0][j1] == z[0][j1 + 1] &&
					z[1][j1] == z[1][j1 + 1] &&
					z[2][j1] < z[2][j1+1]))
				Change(z, rowCount, j1,j1+1);
}
void Change(int** z,  const int rowCount, const int col1, const int col2)
{
	int tmp;
	for (int i = 0; i < rowCount; i++)
	{
		tmp = z[i][col1];
		z[i][col1] = z[i][col2];
		z[i][col2] = tmp;
	}
}
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if ( !(z[i][j] % 2 != 0) && !(z[i][j] % 7 == 0))
			{
				S += z[i][j];
				k++;
				z[i][j] = 0;
			}
}
