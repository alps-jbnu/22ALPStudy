#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll see_count = 0;
	int n;
	cin >> n;

	// first에는 키 값을 second에는 같은 키의 수 저장
	stack<pair<int, int> > s;

	for (int i = 0; i < n; i++)
	{
		int same = 1; // same: 같은 키의 수
		int height;
		cin >> height;

		// 
		while (!s.empty() && s.top().X <= height)
		{
			if (s.top().X == height)
			{
				see_count += s.top().Y;
				same = s.top().Y + 1;
				s.pop();
			}
			else
			{
				see_count += s.top().Y;
				s.pop();
				same = 1; // 같은 키의 수 1로 초기화
			}
		}

		// 인접한 키들 고려
		if (!s.empty()) see_count++;
		s.push({ height, same });
	}
	cout << see_count;
	return 0;
}

/*
이 문제의 핵심은 같은 키가 나왔을 경우이다.
same이라는 변수를 만들어 해결
*/
