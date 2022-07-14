#include <iostream>
#include <set>

using namespace std;

bool IsSpot[500001] = { false };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set<int> s;
	int n,q,cur_pos=1;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if (temp)
		{
			s.insert(i);
			IsSpot[i] = true;
		}
	}
	for (int i = 0; i < q; i++)
	{
		int option;
		cin >> option;
		switch (option)
		{
		case 1:
			int spot;
			cin >> spot;
			if (IsSpot[spot]) s.erase(spot);
			else s.insert(spot);
			IsSpot[spot] ^= true;
			break;
		case 2:
			int step_num;
			cin >> step_num;
			cur_pos += step_num;
			cur_pos = cur_pos % n;
			if (cur_pos == 0) cur_pos = n;
			break;
		default:
			auto at = s.upper_bound(cur_pos);
			if (s.empty()) cout << -1 << "\n"; //명소 없을때
			else if (IsSpot[cur_pos]) cout << 0 << "\n"; //현재 위치 명소일때
			else if (at == s.end()) cout << n + *s.begin() - cur_pos << "\n"; // 명소가 현재 위치보다 뒤에 있어서 한바퀴 돌때 
			else cout << *at - cur_pos << "\n";
			break;
		}
	}

	return 0;
}