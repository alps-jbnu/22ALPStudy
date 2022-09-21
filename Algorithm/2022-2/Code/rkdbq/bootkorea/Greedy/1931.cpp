#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int main(void) {
	int N, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	sort(vec.begin(), vec.end(), cmp);

	int min = vec[0].second;
	cnt++;

	for (int i = 1; i < N; i++)
	{
		if (vec[i].first >= min)
		{
			min = vec[i].second;
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}