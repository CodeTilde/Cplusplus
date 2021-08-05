#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
int N, temp, fir, sec1, sec2;
vector<int>vec;
map<int, vector<int>> mymap;
cin >> N;
map<int, vector<int>>::iterator itr;
vector<int> temp_vec;
for (int i = 0; i < N; i++)
{
cin >> temp;
vec.push_back(temp);
}
for (int i = 0; i < N - 1; i++)
for (int j = i + 1; j < N; j++)
{



if (find(mymap[vec[i]].begin(), mymap[vec[i]].end(), vec[j]) == mymap[vec[i]].end())//it implicitly insert the key only the key .
{

mymap[vec[i]].push_back(vec[j]);
}


}
int sum = 0;

for (itr = mymap.begin(); itr != mymap.end(); itr++)
{
temp_vec = itr->second;
sum += temp_vec.size();
}

cout << sum;
cin >> N;
return 0;
}
