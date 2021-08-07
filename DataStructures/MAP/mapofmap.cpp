#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int N, temp,
	vector<int>vec;
	map<int, map<int ,int>> mymap;
	cin >> N;
	map<int, map<int, int>>::iterator itr;
	vector<int> temp_vec;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < N - 1; i++)
	{
		if (mymap[vec[i]].size() == 0)
		{


			for (int j = i + 1; j < N; j++)
				mymap[vec[i]][vec[j]] = vec[j];
				
		}


	}
	int sum = 0;

	for (itr = mymap.begin(); itr != mymap.end(); itr++)
	{
		 
		
		sum += (itr->second).size();
	}

	cout << sum;
	cin >> N;
	return 0;
}
