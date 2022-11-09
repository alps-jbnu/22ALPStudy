#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;

bool compare(const pair<int, string> x, const pair<int, string> y)
{
	return x.first < y.first;
}

int main()
{
	cin >> N;
	vector<pair<int, string>> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	stable_sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}

	return 0;
}