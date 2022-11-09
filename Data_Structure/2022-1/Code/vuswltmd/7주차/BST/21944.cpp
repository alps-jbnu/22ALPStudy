#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

string op;
int N, P, L, G, M;

pair<int, int> probLevel[100002]; //문제(난이도, 분류) 저장
set<int> probByL[102]; // 난이도 별 저장
set<int> probByGL[102][102]; // (분류, 난이도) 별 저장



int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num, level, al;
		cin >> num >> level >> al;

		probLevel[num] = { level, al };
		probByL[level].insert(num);
		probByGL[al][level].insert(num);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> op;

		if (op == "recommend")
		{
			cin >> G;
			int x; cin >> x;
			
			if (x == 1)
			{
				for (int i = 100; i >= 1; i--)
				{
					if (probByGL[G][i].empty()) continue;
					cout << *prev(probByGL[G][i].end()) << '\n';
					break;
				}
			}
			else if (x == -1)
			{
				for (int i = 1; i <= 100; i++)
				{
					if (probByGL[G][i].empty()) continue;
					cout << *probByGL[G][i].begin() << '\n';
					break;
				}
			}
		}
		else if (op == "recommend2")
		{
			int x; cin >> x;

			if (x == 1)
			{
				for (int i = 100; i >= 0; i--)
				{
					if (probByL[i].empty()) continue;
					cout << *prev(probByL[i].end()) << '\n';
					break;
				}
				
			}
			else if (x == -1)
			{
				for (int i = 0; i <= 100; i++)
				{
					if (probByL[i].empty()) continue;
					cout << *probByL[i].begin() << '\n';
					break;
				}
			}
		}
		else if (op == "recommend3")
		{
			int x; cin >> x;
			cin >> L;
			int ans = -1;

			if (x == 1)
			{
				for (int i = L; i <= 100; i++)
				{
					if (probByL[i].empty()) continue;
					cout << *probByL[i].begin() << '\n';
					break;
				}
			}
			else if (x == -1)
			{
				for (int i = L-1; i >= 0; i--)
				{
					if (probByL[i].empty()) continue;
					cout << *prev(probByL[i].end()) << '\n';
					break;
				}
			}
			cout << ans << '\n';
		}
		else if (op == "add")
		{
			cin >> P >> L >> G;

			probLevel[P] = { L, G };
			probByL[L].insert(P);
			probByGL[G][L].insert(P);

		}
		else if (op == "solved")
		{
			cin >> P;
			tie(L, G) = probLevel[P];
			
			probByL[L].erase(P);
			probByGL[G][L].erase(P);
			/*probLevel[num] = { level, al };
			probByL[level].insert(num);
			probByGL[al][level].insert(num);*/

		}
	}
}