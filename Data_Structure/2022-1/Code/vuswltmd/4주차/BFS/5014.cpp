#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

int F, S, G, U, D;
int dist[1000005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> F >> S >> G >> U >> D;
	D = D * -1;

	for (int i = 1; i <= F; i++)
	{
		dist[i] = -1;
	}
	
	queue<int> Q;
	Q.push(S);
	dist[S] = 0;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (auto dir : { U, D })
		{
			int nxt = cur + dir;

			if (nxt > F || nxt < 1) continue;
			if (dist[nxt] != -1 ) continue;

			dist[nxt] = dist[cur] + 1;

			Q.push(nxt);
		}
	}

	if (dist[G] == -1)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << dist[G];
	}
	

}