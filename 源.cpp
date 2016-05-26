#include<iostream>
using namespace std;

#define N 4
#define C 8
int weight[N] = { 1, 4, 2, 3 };
int value[N] = { 2, 1, 4, 3 };
int dpTable[N][C];

int max(int a, int b)
{
	return a > b ? a : b;
}

int maxValue(int minThing, int capacity)
{
	if (minThing == N)
	{
		if (dpTable[minThing][capacity] == -1)
		{
			if (weight[minThing] <= C)
				dpTable[minThing][capacity] = value[minThing];
			else
				dpTable[minThing][capacity] = 0;
		}
		else
			return dpTable[minThing][capacity];
	}
	else
	{
		if (dpTable[minThing][capacity] != -1)
		{
			return dpTable[minThing][capacity];
		}
		else
		{
			return dpTable[minThing][capacity] = max(maxValue(minThing + 1, capacity), maxValue(minThing, capacity - weight[minThing]) + value[minThing]);
		}
	}
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < C; j++)
		{
			dpTable[i][j] = -1;
		}
	}

}