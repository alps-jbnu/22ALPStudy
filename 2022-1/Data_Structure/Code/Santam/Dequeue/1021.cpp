#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int result = 0;
	queue<int> q;

	for (int i = 1;i <= n;i++)
	{
		q.push(i);
	}

	for (int i = 0;i < m;i++)
	{
		int temp;
		cin >> temp;
		int shift_cnt = 0;
		while (q.front() != temp)
		{
			q.push(q.front());
			q.pop();
			shift_cnt++;
		}
		if (shift_cnt > (q.size() - shift_cnt))  result += (q.size() - shift_cnt);
		else result += shift_cnt;
		q.pop();		
	}

	cout << result<<endl;

	return 0;
}

/*
1.큐에서 어차피 값은 pop해야 되는 곳이 front부분 뿐이기 때문에 큐로 해결해도 된다고 생각

2.먼저 n까지의 값을 큐에 넣고 계속 front부분을 pop해서 back부분으로 push해가면서 temp랑 비교하는 데, pop한 횟수를 카운트 해준다.

3.front값과 temp가 같을때 그동안 pop한 횟수와 size값에서 pop한 횟수를 뺀 값을 서로 비교하면 왼쪽 shift연산과 오른쪽 shift연산중 어떤게 최소 연산일지 알 수 있다.

4.각 케이스 값들의 최소 연산 결과를 result에 더해주고 마지막에 출력
*/