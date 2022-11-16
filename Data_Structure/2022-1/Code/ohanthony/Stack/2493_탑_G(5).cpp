#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<pair<int,int>> s;
	for (int i = 1; i <= n; i++)
	{
		int height;
		cin >> height;

		// height 값이 top() 보다 높이가 크다면 top()값이 height 보다 클때까지 pop 진행 
		while (!s.empty() && s.top().Y < height)
		{
			s.pop();
		}
		if (s.empty())
		{
			cout << 0 << " ";
		}
		else if (!s.empty() && s.top().Y > height)
		{
			cout << s.top().X << " ";
		}
		s.push({i, height});
	}
	
	return 0;
}
