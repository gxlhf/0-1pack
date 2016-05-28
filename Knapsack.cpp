#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

int n, c;
int* weight;
int* value;
int** dpTable;
bool* result;

int max(int a, int b)
{
	return a > b ? a : b;
}

void trackBack(int i, int j)
{
	if (i == n - 1)
	{
		result[i] = (dpTable[i][j] != 0);
		return;
	}
	result[i] = (dpTable[i][j] != dpTable[i + 1][j]);
	if (result[i])
		trackBack(i + 1, j - weight[i]);
	else
		trackBack(i + 1, j);
}

void Knapsack()
{
	for (int i = 0; i < weight[n - 1]; i++)
		dpTable[n - 1][i] = 0;
	for (int i = weight[n - 1]; i < c; i++)
		dpTable[n - 1][i] = value[n - 1];

	for (int i = n - 2; i > 0; i--)
	{
		for (int j = 0; j < c; j++)
		{
			if (j >= weight[i])
				dpTable[i][j] = max(dpTable[i + 1][j], dpTable[i + 1][j - weight[i]] + value[i]);
			else
				dpTable[i][j] = dpTable[i + 1][j];
		}
	}

	dpTable[0][c - 1] = max(dpTable[1][c - 1], dpTable[1][c - 1 - weight[0]] + value[0]);

	trackBack(0, c - 1);
}

int main()
{
	c = 1000;
	n = 100;
	weight = new int[n]{71, 34, 82, 23, 1, 88, 12, 57, 10, 68, 5, 33, 37, 69, 98, 24, 26, 83, 16, 26, 18, 43, 52, 71, 22, 65, 68, 8, 40, 40, 24, 72, 16, 34, 10, 19, 28, 13, 34, 98, 29, 31, 79, 33, 60, 74, 44, 56, 54, 17, 63, 83, 100, 54, 10, 5, 79, 42, 65, 93, 52, 64, 85, 68, 54, 62, 29, 40, 35, 90, 47, 77, 87, 75, 39, 18, 38, 25, 61, 13, 36, 53, 46, 28, 44, 34, 39, 69, 42, 97, 34, 83, 8, 74, 38, 74, 22, 40, 7, 94};
	value = new int[c]{26, 59, 30, 19, 66, 85, 94, 8, 3, 44, 5, 1, 41, 82, 76, 1, 12, 81, 73, 32, 74, 54, 62, 41, 19, 10, 65, 53, 56, 53, 70, 66, 58, 22, 72, 33, 96, 88, 68, 45, 44, 61, 78, 78, 6, 66, 11, 59, 83, 48, 52, 7, 51, 37, 89, 72, 23, 52, 55, 44, 57, 45, 11, 90, 31, 38, 48, 75, 56, 64, 73, 66, 35, 50, 16, 51, 33, 58, 85, 77, 71, 87, 69, 52, 10, 13, 39, 75, 38, 13, 90, 35, 83, 93, 61, 62, 95, 73, 26, 85};
	dpTable = new int*[n];

	/*计时*/
	double  k = 0.0;
	clock_t start, end, over;
	start = clock();
	end = clock();
	over = end - start;
	start = clock();


	if (!dpTable)
		exit(1);

	for (int i = 0; i < n; i++)
	{
		dpTable[i] = new int[c];
		if (!dpTable[i])
			exit(1);
	}

	result = new bool[n];

	Knapsack();

	/*计时*/
	end = clock();
	printf("The time is %6.3f\n", (double)(end - start - over) / CLK_TCK);

	
	cout << dpTable[0][c - 1] << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}

	cout << endl;
	system("pause");
}