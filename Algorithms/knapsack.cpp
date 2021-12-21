//Knapsack problem: solved by exhaustive search and implemented by recursive function
// Worst case complexity: 2^{n}


#include <iostream>
#include <vector>
using namespace std;
void F(int n, int N,  int * W, int* V, int w, int sum, int& maxsum)
{
	if ((n <N) & (w>=0))
	{
		cout << " W_" << n << 0 << " "<<" w="<<w; 
		F(n+1, N, W, V, w, sum, maxsum );
		if ((w - W[n]) >= 0)
		{
				F(n + 1, N, W, V, w - W[n], sum + V[n], maxsum);
		}
	}
	else
	{
		if (sum > maxsum)
			maxsum = sum;		
	}
}


int main()
{
	int W[] = { 1,1,2,12,4 }; 
	int V[] = { 1, 2, 2,  4,10 };
	int w = 15;

	int N = sizeof(V) / sizeof(V[0]);
	int sum = 0;
	int maxsum = 0; 
	int n = 0;
	F(n, N, W, V, w, sum, maxsum);
	cout << maxsum;
	return 0;
}
