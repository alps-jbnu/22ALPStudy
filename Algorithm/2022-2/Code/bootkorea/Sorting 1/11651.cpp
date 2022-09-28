#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

bool Sorting(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second) return 1;
	else if (a.second == b.second)
	{
		if (a.first < b.first) return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(), vec.end(), Sorting);

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}

	return 0;
}