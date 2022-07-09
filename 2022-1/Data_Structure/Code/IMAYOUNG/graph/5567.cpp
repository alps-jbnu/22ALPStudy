#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int>v[10001];
int t1, t2;
set<int>s;

void bfs(int start)
{
	queue<pair<int, int>>q;
	q.push({ start,0 });

	while (!q.empty())
	{
		int qx = q.front().first;
		int qcnt = q.front().second;
		q.pop();

		if (qcnt > 2)continue;	//qcnt가 2보다 크다면 상근이의 친구 및 친구의친구가 아닌경우

		s.insert(qx);

		for (int i = 0; i < v[qx].size(); i++)
			q.push({v[qx][i], qcnt+1});
	}
}


int main()
{	
	ios::sync_with_stdio(0);
    	cin.tie(0);

	cin >> n;	//동기의 수
	cin >> m;	//리스트의 길이

	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		v[t1].push_back(t2);	//양방향으로 연결
		v[t2].push_back(t1);
	}

	bfs(1);	
	
	cout << s.size()-1;	//set의 size가 상근이와 연결된 동기의수, 상근이는 빼야함으로 -1

	return 0;
}