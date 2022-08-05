#include <iostream>
#include <algorithm>
#include <deque>
#define MAX 5000000 + 1
using namespace std;

int N, L;
int arr[MAX];
deque<pair<int, int>> dq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (!dq.empty())
		{
			if (dq.front().second < i - L + 1)
			{
				dq.pop_front();
			}
		}
		while (!dq.empty() && dq.back().first > arr[i])
		{
			dq.pop_back();
		}
		dq.push_back({ arr[i], i });
		
		cout << dq.front().first << " ";
	}

	return 0;
}