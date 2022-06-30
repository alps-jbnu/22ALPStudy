#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		priority_queue<int> temp;
		for (int j = 0; j < n; j++)
		{
			int t;
			cin >> t;
			if (q.empty()) q.push(t);
			else
			{
				if (q.top() <= t) temp.push(t);
				else
				{
					temp.push(q.top()); q.pop();
					q.push(t);
				}
			}
		}
		q = temp;
	}
	for (int i = 0; i < n-1; i++) q.pop();
	cout << q.top();
}

/*
단순히 n*n개의 데이터를 힙에다 넣으면 메모리 초과가 되므로 다음 줄의 데이터들이 들어올때 기존의 힙에 있는 값과 새로 들어오는 데이터를 비교해 큰것들로 n개를 새로 넣은 힙을 갱신하는 메커니즘
1. 최대힙하나를 만들고 첫줄의 n개 데이터가 들어오면 push해준다.
2. 두번째 줄 n개의 데이터가 들어오면 새로운 힙하나를 만들고 기존 힙과 새로 들어오는 데이터를 비교해준다.
3. 기존의 데이터가 작을때는 새로 들어오는 데이터를 새로운 힙에 넣는다.
4. 그게 아니라면, 기존의 데이터를 새로운 힙에 넣고 기존의 데이터를 지우고 새로 들어온 데이터는 기존 힙에 넣어준다.
5. 4의 과정을 n번 반복하면 새로운 힙의 최소값은 기존힙의 최대값보다 클수 밖에 없다. ==> 출력할 데이터는 n번째 큰 값이므로 n번째보다 작은 수는 다 버린다는 생각으로
*/