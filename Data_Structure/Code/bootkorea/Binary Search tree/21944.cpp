#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
using namespace std;
const int MAX = 100000 + 1;
typedef pair<int, int> pii;

int N, M, cnt = 0;
pair<int, int> Lv[MAX];
string str;
priority_queue<pii> HARD[MAX];
priority_queue<pii, vector<pii>, greater<pii>> EASY[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int p, l, g;
		cin >> p >> l >> g;

		HARD[g].push({ l, p });
		EASY[g].push({ l, p });
		Lv[p] = { l, g };

		cnt = max(cnt, g);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (str == "add")
		{
			int p, l, g;
			cin >> p >> l >> g;
			HARD[g].push({ l, p });
			EASY[g].push({ l, p });
			Lv[p] = { l, g };

		}
		else if (str == "solved")
		{
			int x; cin >> x;

			Lv[x] = { 0, 0 };
		}
		else
		{

			if (str == "recommend")
			{
				int g, x;
				cin >> g >> x;
				if (x == 1)
				{
					while (1)
					{
						int p = HARD[g].top().second;
						int l = HARD[g].top().first;

						if (Lv[p] == make_pair(l, g)) break;
						HARD[g].pop();
					}
					cout << HARD[g].top().second << "\n";
				}
				else
				{
					while (1)
					{
						int p = EASY[g].top().second;
						int l = EASY[g].top().first;

						if (Lv[p] == make_pair(l, g)) break;
						EASY[g].pop();
					}
					cout << EASY[g].top().second << "\n";
				}
			}
			else if (str == "recommend2")
			{
				int x, num = 0; cin >> x;

				if (x == 1)
				{
					for (int g = 1; g <= cnt; g++)
					{
						int p, l;
						while (1)
						{
							p = HARD[g].top().second;
							l = HARD[g].top().first;

							if (Lv[p] == make_pair(l, g)) break;
							HARD[g].pop();
						}

						num = max(num, HARD[g].top().second);
					}
					cout << num << "\n";
				}
				else
				{
					for (int g = 1; g <= cnt; g++)
					{
						int p, l;
						while (1)
						{
							p = EASY[g].top().second;
							l = EASY[g].top().first;

							if (Lv[p] == make_pair(l, g)) break;
							EASY[g].pop();
						}

						num = min(num, EASY[g].top().second);
					}
					cout << num << "\n";
				}
			}
			else
			{
				int x, L, num = 0; cin >> x >> L;
				if (x == 1)
				{
					for (int g = 1; g <= cnt; g++)
					{
						int p, l;
						while (1)
						{
							p = HARD[g].top().second;
							l = HARD[g].top().first;

							if (Lv[p] == make_pair(l, g)) break;
							HARD[g].pop();
						}

						if (HARD[g].top().second >= L)
						{
							num = max(num, HARD[g].top().second);
						}

					}
					cout << num << "\n";
				}
				else
				{
					for (int g = 1; g <= cnt; g++)
					{
						int p, l;
						while (1)
						{
							p = EASY[g].top().second;
							l = EASY[g].top().first;

							if (Lv[p] == make_pair(l, g)) break;
							EASY[g].pop();
						}

						if (EASY[g].top().second >= L)
						{
							num = max(num, EASY[g].top().second);
						}

					}
					cout << num << "\n";
				}
			}
		}
	}

	return 0;
}