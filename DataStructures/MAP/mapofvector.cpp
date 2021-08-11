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
// Reading the numbers and putting them in a vector 
for (int i = 0; i < N; i++)
{
cin >> temp;
vec.push_back(temp);
}
//Placing the vector elements in a map 
// e.g. for a vector of numbers such as   1 2 3 4 3 2 5 6
// 1 is a key and the map value is the vector 2, 3, 4, 5, 6  
// 2 is a key and the map value is the vector 3, 4, 2, 5, 6
//...
for (int i = 0; i < N - 1; i++)
  //vec[i] indicates the key and vec[j] indicates an element of the vector (map value)
  for (int j = i + 1; j < N; j++)
     // for each key (vec[i]) the map value which is a vector is checked to avoid repetetive elements.
    if (find(mymap[vec[i]].begin(), mymap[vec[i]].end(), vec[j]) == mymap[vec[i]].end())//it implicitly insert the key only the key .
      mymap[vec[i]].push_back(vec[j]);

int sum = 0;

for (itr = mymap.begin(); itr != mymap.end(); itr++)
{
temp_vec = itr->second;
sum += temp_vec.size();
}

cout << sum;
return 0;
}
