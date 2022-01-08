//Unbounded Knapsack solved by dynamic programming 
//The complexity is 
#include <iostream>
#include <vector>
using namespace std;
int maxfunction(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	int N;
	int W = 50;
	int k = 0;
	int value1;
	int value2; 
	int val;
	//vector<int> v = { 3, 4, 4, 10, 4 };  
	//vector<int> w = { 3, 4, 5, 9, 4 };
	//vector<int> v = { 4, 2, 1, 2, 10 };
	//vector<int> w = { 12, 2, 1, 1, 4 };
	vector <int> w = { 7, 3, 20 };
	vector <int> v = { 12, 2, 41 };
	//W = 11;
	//W = 15;
	//N = 5;
	W = 58;
	N = 3;
	vector<vector<int>> A(N + 1, vector<int>(W + 1, 0));
	for (int i = 1; i < N +1; i++)
	{
		for (int j = 1; j < W + 1; j++)
		{
			if (j < w[i - 1])
				A[i][j] = A[i - 1][j];
			else
			{
				value1 = v[i - 1] + A[i - 1][j - w[i - 1]];
				value2 = v[i - 1] + A[i][j - w[i - 1]];
				val = maxfunction(value1, value2);
				A[i][j] = maxfunction(val, A[i - 1][j]);
			}
		}
	}
	cout << endl << A[N][W];
	return 0;
}
