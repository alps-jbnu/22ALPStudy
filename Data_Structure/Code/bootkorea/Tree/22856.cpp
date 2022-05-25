#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 100000 + 1;

int N, cnt = -1, right_cnt;
map<int, pair<int, int>> vec;

// 중위 순회
void InOrder(int cur, int flag)
{
	if (cur == -1) return;

	cnt++;
	InOrder(vec[cur].first, 0);

	if (flag)
	{
		right_cnt++;
		InOrder(vec[cur].second, 1);
	}
	else InOrder(vec[cur].second, 0);
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		vec[x].first = y;
		vec[x].second = z;
	}

	InOrder(1, 1);
	cout << 2 * cnt - right_cnt + 1;

	return 0;
}