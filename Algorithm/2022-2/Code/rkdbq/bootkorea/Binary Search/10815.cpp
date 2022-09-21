#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec1;

bool Solve(int num)
{
	int start = 0, end = vec1.size() - 1;
	int mid = (start + end) / 2;

	while (start <= end)
	{
		if (vec1[mid] == num)
		{
			return 1;
		}
		if (vec1[mid] > num)
		{
			end = mid - 1;
		}
		if (vec1[mid] < num)
		{
			start = mid + 1;
		}

		mid = (start + end) / 2;
	}

	return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	vec1 = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> vec1[i];
	}

	cin >> M;
	vector<int> vec2(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> vec2[i];
	}

	sort(vec1.begin(), vec1.end());

	for (int i = 0; i < M; i++)
	{
		cout << Solve(vec2[i]) << " ";
	}

	return 0;
}