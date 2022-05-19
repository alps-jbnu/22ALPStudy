#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int vis[501];
vector<int> v[501];

int main()
{
	int _case = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		_case++;

		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0)
		{
			break;
		}

		for (int i = 0; i < y; i++)
		{
			int a, b;
			cin >> a >> b;

			v[a].push_back(b);
			v[b].push_back(a);
		}

		
		int num = 0;
		int treenum = 0;

		for (int i = 1; i <= x; i++)
		{
			if (vis[i] == 0)
			{
				queue<pair<int, int>> q;
				q.push({ i, -1 });
				vis[i] = 1;
				bool cycle = false;

				while (!q.empty())
				{
					int cur = q.front().first; 
					int parent = q.front().second;
					q.pop();
					for (int nxt : v[cur])
					{
						if (nxt != parent)
						{
							if (vis[nxt] == 0)
							{
								vis[nxt] = 1;
								q.push({ nxt, cur });
							}
							else
							{
								cycle = true;
								break;
							}
						}
						
					}
					if (cycle) continue;
				}
				if (cycle == false)
					num++;
			}
			
		}

		string answer = "";
		if (num==0) {
			cout << "Case " << _case << ": ";
			cout << "No trees.\n";
		}
		else if (num == 1) {
			cout << "Case " << _case << ": ";
			cout << "There is one tree.\n";
		}
		else {
			cout << "Case " << _case << ": ";
			cout << "A forest of " << num << " trees.\n";
		}
		

		for (int i = 0; i <= x; i++)
		{
			vis[i] = 0;
			v[i].clear();
		}
		

	}

	// 11724 Âü°í

}