//Knapsack problem: solved by exhaustive search and implemented by recursive function
// Worst case complexity: 2^{n}
#include <iostream>
#include <vector>
using namespace std;
void F(int n, int N,  int * W, int* V, int w, int sum, int& maxsum, int* path, int* path_o)
{
	if ((n <N) & (w>=0))
	{
		path[n] = 0;
		for (auto y = n + 1; y < N; y++)
			path[y] = 0;
		F(n+1, N, W, V, w, sum, maxsum, path, path_o );
		if ((w - W[n]) >= 0)
		{

			path[n] = 1;
			for (auto y = n + 1; y < N; y++)
				path[y] = 0;
			F(n + 1, N, W, V, w - W[n], sum + V[n], maxsum,path, path_o);
		}
		
	
	
		
	}
	else
	{

		if (sum > maxsum)
		{
				maxsum = sum;
				for (auto x = 0; x < N; x++)
					path_o[x] = path[x];
		}
				
	}
	

}

int main()
{
	int W[] = { 3, 4, 5, 9, 4 }; 
	int V[] = { 3, 4, 4, 10, 4 };
	int w = 11;
	int N = sizeof(V) / sizeof(V[0]);
	int* path;
	int* path_o;
	path = new int[N];
	path_o = new int[N];
	int sum = 0;
	int maxsum = 0; 
	int n = 0;
	F(n, N, W, V, w, sum, maxsum, path, path_o);
	cout << maxsum<<endl;
	for (auto y = 0; y < N; y++)
		cout << path_o[y];
	delete path;
	delete path_o;
	return 0;
}
