#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1;i <= n;i++)
	{
		q.push(i);
	}
	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front()<<endl;
}

/*
1. 순서대로 n까지 줄을 서는데 먼저 줄을 선 사람은 줄에서 이탈하고 그 뒤에 있던 사람은 줄의 맨뒤로 돌아간다고 생각을 했다.

2. 먼저, 줄을 가장 먼저 섰던 첫번째 사람이 가장 먼저 줄을 이탈하기에 큐와 같다는 생각을 가지고 큐을 이용했다.

3. 줄을 섰던 첫번째사람이 먼저 이탈하므로, pop을 해준다.

4. 그 직후에 두번째 사람은 줄의 맨뒤로 이동해야하므로 front값을 다시 push해서 줄의 맨뒤로 보냈다.

5. 위의 과정을 반복하면서 줄의 size가 1이되면 남아 있는 사람을 출력한다.
*/