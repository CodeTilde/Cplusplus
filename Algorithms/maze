#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int  main()
{
	vector<vector<int>> vect = { { 0, 0, 0, 0,0 },
	{ 0, -1, 0, 0, 0 },
	{ -1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0 , 0} };
	int R = vect.size();
	int C = vect[0].size();
	int a = 0;
	int b = 0;
	vector<vector<int>> A(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (vect[i][j] == 0)
			{
				if (i == 0)
					a = 0;
				else
					a = A[i - 1][j];
				if (j == 0)
					b = 0;
				else
					b = A[i][j - 1];
				if ((i == 0) && (i == 0))
					A[i][j] = 1;
				else
					A[i][j] = a + b;
			}
			else
			{
				A[i][j] = 0;
			}

		}
		cout << A[R-1][C-1] << endl;		 
	return 0;
}
