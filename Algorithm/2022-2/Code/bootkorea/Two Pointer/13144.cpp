#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 100000 + 1;
using namespace std;

ll N;
ll result = 0;
bool Visited[MAX];
vector<int> vec;

int main()
{
	cin >> N;
	vec.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	for (int left = 0, right = 0; left < N; left++)
	{
		while (right < N)
		{
			if (Visited[vec[right]]) break;
			Visited[vec[right]] = 1;
			right++;
		}
		result += (right - left);
		Visited[vec[left]] = 0;
	}

	cout << result;

	return 0;
}