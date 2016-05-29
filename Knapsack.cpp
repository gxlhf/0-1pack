#include<ctime>
#include<iostream>
#include<iomanip>
#include<fstream>

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

void trackBack()
{
	/*if (i == n - 1)
	{
		result[i] = (dpTable[i][j] != 0);
		return;
	}
	result[i] = (dpTable[i][j] != dpTable[i + 1][j]);
	if (result[i])
		trackBack(i + 1, j - weight[i]);
	else
		trackBack(i + 1, j);*/
	int i = 0, j = c - 1;
	while (i < n - 1)
	{
		result[i] = (dpTable[i][j] != dpTable[i + 1][j]);
		if (result[i])
			j -= weight[i];
		i++;
	}
	result[n - 1] = (dpTable[n - 1][j] != 0);
}

void Knapsack()
{
	for (int i1 = 0; i1 < weight[n - 1]; i1++)
		dpTable[n - 1][i1] = 0;
	for (int i2 = weight[n - 1]; i2 < c; i2++)
		dpTable[n - 1][i2] = value[n - 1];

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

	trackBack();
}

int main()
{
	ifstream input("big_data.txt");
	if (!input.is_open())
		exit(2);

	input >> n >> c;
	weight = new int[n];
	value = new int[c];
	dpTable = new int*[n];	
	if (!dpTable)
		exit(1);
	for (int i = 0; i < n; i++)
	{
		dpTable[i] = new int[c];
		if (!dpTable[i])
			exit(1);
	}
	result = new bool[n];

	for (int i = 0; i < n; i++)
		input >> weight[i];

	for (int i = 0; i < n; i++)
		input >> value[i];

	/*计时*/
	double  k = 0.0;
	clock_t start, end, over;
	start = clock();
	end = clock();
	over = end - start;
	start = clock();

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