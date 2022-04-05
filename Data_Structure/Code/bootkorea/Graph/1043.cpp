#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 50 + 1
using namespace std;

int N, M, K, result = 0;
int arr[MAX];
vector<int> vec;
vector<int> vec2[MAX];

int Find(int x)
{
	if (x == arr[x]) return x;

	return arr[x] = Find(arr[x]);
}

int Unite(int x, int y)
{
	x = Find(x);
	y = Find(y);

	arr[y] = x;
	return arr[y];
}

bool Same_Parent(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	while (K--)
	{
		int temp;
		cin >> temp;

		vec.push_back(temp);
	}

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			int a;
			cin >> a;
			vec2[i].push_back(a);
		}
	}
	result = M;

	for (int i = 1; i <= N; i++) arr[i] = i;
	for (int i = 0; i < M; i++)
	{
		int x = vec2[i][0];

		for (int j = 1; j < vec2[i].size(); j++)
		{
			int y = vec2[i][j];
			Unite(x, y);
		}
	}

	for (int i = 0; i < M; i++)
	{
		bool temp = true;

		for (int j = 0; j < vec2[i].size(); j++)
		{
			if (temp == 0) break;
			int x = vec2[i][j];

			for (int k = 0; k < vec.size(); k++)
			{
				int y = vec[k];

				if (Same_Parent(x, y) == 1)
				{
					temp = 0;
					break;
				}
			}
		}
		if (temp == 0) result--;
	}
	cout << result;

	return 0;
}