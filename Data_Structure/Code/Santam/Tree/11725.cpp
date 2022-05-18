#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
int p[100001] = { 0 };

void Bfs(int cur)
{
	queue<int> q;
	q.push(cur);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0;i < v[cur].size();i++)
		{
			if (p[cur] == v[cur][i]) continue; //부모의 노드만을 기록하는 것이기에, 자식이 부모를 저장하는 것 외에 반대의 경우가 없도록 조건을 넣음
			p[v[cur][i]] = cur;
			q.push(v[cur][i]);
		}
	}
}

int main()
{

	int n;
	cin >> n;
	for (int i = 0;i < n-1;i++)
	{
		int temp,temp2;
		cin >> temp >> temp2;
		v[temp].push_back(temp2);
		v[temp2].push_back(temp);
	}
	Bfs(1);
	for (int i = 2; i < n+1; i++)
	{
		cout << p[i] << "\n";
	}

	return 0;
}

/*
이문제에서 각 노드의 부모 노드가 무엇인지 알수 있도록 부모 노드를 저장하는 배열이 있으면 해결할 수 있으리라 생각
1. 각 노드의 연결여부를 벡터배열 변수를 선언해 push_back해주었다.
2. 저장된 벡터에서 bfs를 활용해 각 노드를 순회하면서 루트에서 부터 순서대로 순회할때, 각 노드의 부모가 어떤 노드인지 배열 p에 저장
3. 저장된 배열 p에 있는 데이터를 2번노드부터 순서대로 출력했다.
*/