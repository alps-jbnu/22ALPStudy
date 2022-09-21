#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long count = 0;
	int n;
	cin >> n;
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;

		while (!s.empty() && s.top() <= height)
		{
			s.pop();
		}
		if (!s.empty() && s.top() > height)
		{
			count += s.size();
		}

		s.push(height);
	}

	cout << count;
	return 0;
}

/*
- stack의 길이를 활용하여 해결

(monotone stack)
: 스택의 원소들을 O(n)의 시간복잡도로 오름차순 혹은 내림차순 상태로 유지하는 방법
- 스택의 top에 있는 숫자와 새롭게 들어오는 숫자를 비교하고, 경우에 따라 pop하며 진행
*/