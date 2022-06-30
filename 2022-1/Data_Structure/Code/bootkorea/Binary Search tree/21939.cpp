#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
using namespace std;
const int MAX = 100000 + 1;
typedef pair<int, int> pii;

int N, M;
int Lv[MAX];
string str;
priority_queue<pii> HARD;
priority_queue<pii, vector<pii>, greater<pii>> EASY;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int p, l;
		cin >> p >> l;

		HARD.push({ l, p });
		EASY.push({ l, p });
		Lv[p] = l;
	}
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (str == "add")
		{
			int p, l;
			cin >> p >> l;
			HARD.push({ l, p });
			EASY.push({ l, p });
			Lv[p] = l;

		}
		else
		{
			int x;
			cin >> x;
			if (str == "recommend")
			{
				if (x == 1)
				{
					while (1)
					{
						int p = HARD.top().second;
						int l = HARD.top().first;
						
						if (Lv[p] == l) break;
						HARD.pop();
					}
					cout << HARD.top().second << "\n";
				}
				else
				{
					while (1)
					{
						int p = EASY.top().second;
						int l = EASY.top().first;
						
						if (Lv[p] == l) break;
						EASY.pop();
					}
					cout << EASY.top().second << "\n";
				}
			}
			else
			{
				Lv[x] = 0;
			}
		}
	}

	return 0;
}