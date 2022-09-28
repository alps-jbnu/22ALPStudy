#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	// x좌표가 같다면
	if (a.X == b.X) return a.Y < b.Y; // y 좌표를 오름차순으로 정렬
	else return a.X < b.X; // 그 외에 경우 x 좌표를 오름차순으로 정렬
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << v[i].X << " " << v[i].Y << "\n";
	}
	return 0;
}

/*
- vector 활용
- sort 함수의 compare 이해
*/