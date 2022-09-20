#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000 + 1
using namespace std;

int N;
vector<pair<int, int>> vec; // first 실 값, second 순서
vector<int> result(MAX);

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back({ num, i });
	}
	sort(vec.begin(), vec.end());

	int cnt = 0;
	int start = vec[0].first;
	result[vec[0].second] = 0;

	for (int i = 1; i < N; i++)
	{
		if (start == vec[i].first)
		{
			result[vec[i].second] = cnt;
		}
		else
		{
			cnt++;
			result[vec[i].second] = cnt;
			start = vec[i].first;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}