#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test_n;
	cin >> test_n;
	for (int i = 0; i < test_n; i++)
	{
		priority_queue<long long, vector<long long>, greater<long long>> q;
		int page_n;
		long long res = 0;
		cin >> page_n;
		for (int j = 0; j < page_n; j++)
		{
			int p;
			cin >> p;
			q.push(p);
		}
		for (int j = 0; j < page_n-1; j++)
		{
			long long n_1 = q.top(); q.pop();
			long long n_2 = q.top(); q.pop();
			res += n_1 + n_2;
			q.push(n_1 + n_2);
		}
		cout << res << "\n";
	}
}
/*
연습 문제의 카드 정렬하기 문제의 확장팩 버전, 테스터 개수가 여러개로 늘어났다. 메커니즘은 카드정렬하기랑 같으므로 설명은 생략
*/