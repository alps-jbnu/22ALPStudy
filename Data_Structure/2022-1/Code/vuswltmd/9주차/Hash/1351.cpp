#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> mp;
long long N, P, Q;

long long func(long long num)
{
	if (mp.find(num) != mp.end())
	{
		return mp[num];
	}
	else
	{
		return mp[num] = func(num / P) + func(num / Q);
	}
}

int main(void) 
{
	
	cin >> N >> P >> Q;

	mp[0] = 1;

	cout << func(N);
}