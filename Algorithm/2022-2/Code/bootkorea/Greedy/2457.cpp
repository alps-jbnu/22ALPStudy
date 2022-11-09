#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
int s1_date = 300, e1_date = 301;
int idx = 0, e2_date = 0;
int result = 0;
vector<pair<int, int>> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, z, k;
		cin >> x >> y >> z >> k;

		if (x * 100 + y < 301)
		{
			x = 3;
			y = 1;
		}
		else if (z * 100 + k > 1130)
		{
			z = 12;
			k = 1;
		}

		vec.push_back({ x * 100 + y, z * 100 + k });
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		if (vec[i].first > s1_date && vec[i].first <= e1_date)
		{
			if (e2_date < vec[i].second)
			{
				e2_date = vec[i].second;
				idx = i;
			}
			if (vec[i].second == 1201)
			{
				result++;
				e1_date = e2_date;
				break;
			}
			continue;
		}
		else
		{
			if (e1_date >= e2_date) break;
			result++;
			s1_date = e1_date;
			e1_date = e2_date;
			i--;
		}
	}

	if (e1_date == 1201) cout << result;
	else cout << 0;

	return 0;
}