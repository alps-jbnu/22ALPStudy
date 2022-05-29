#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if(t) q.push(t);
		else
		{
			if (q.empty()) cout << 0 << "\n";
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}
	return 0;
}
/*
연습문제의 절댓값 힙문제랑 유사, 난이도가 절댓값 힙문제보다도 쉬운 편이고 설명은 절댓값 힙과 같으므로 생략
*/