#include<fstream>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	ofstream out("small_data.txt");
	int n = 100;
	
	srand(time(0));

	/*output n & c*/
	out << n << ' ' << rand() % 1000 << endl;

	/*output weight*/
	for (int i = 0; i < n; i++)
	{
		out << rand() % 100 << " ";
	}
	out << endl;

	/*output value*/
	for (int i = 0; i < n; i++)
	{
		out << rand() % 100 << " ";
	}
	out << endl;



	//system("pause");
	return 0;
}