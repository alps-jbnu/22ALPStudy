#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<long long, vector<long long>, greater<long long>> q;
	int n;
	long long pre,res=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		q.push(t);
	}
	if (n >= 2)
	{
		for (int i = 0; i < n - 1; i++)
		{
			long long num_1 = q.top(); q.pop();
			long long num_2 = q.top(); q.pop();
			res += num_1+num_2;
			q.push(num_1+num_2);
		}
	}
	cout << res;
	return 0;
}
/*
이 문제의 요점은 합친 카드를 다시 우선 순위 큐에 넣어서 비교가 되어야 된다는 점이다.
1. 카드 묶음의 수들을 최소 힙에 넣는다.
2. n이 1일 경우는 0이라는 점만 주의하고, n==2부터는 우선 순위에서 가장 작은 두 카드 묶음을 꺼내서 더한 값을 결과에 더한다.
3. 2의 과정에서 결과에 더한 두 카드 묶음의 합을 다시 최소 힙에 넣는다.==> 두 카드 묶음의 합이 카드 묶음의 최소는 아니기 때문에
*/