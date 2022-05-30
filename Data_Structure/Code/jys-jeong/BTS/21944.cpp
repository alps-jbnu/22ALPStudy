#include<iostream>
#include<set>
#include<string>
using namespace std;

pair<int, int> pro[100001];

int main() {

	int n, m;
	cin >> n;
	set<int> s[102][102];//int는 문제번호 첫번째 인덱스 난이도 두번째 인덱스 알고리즘 분류
	set<int> s1[102];//index 난이도
	for (int i = 0; i < n; i++) {
		int p, l, g;
		cin >> p >> l >> g; //p 문제번호 l 난이도 g 알고리즘 분류
		s[g][l].insert(p);
		s1[l].insert(p);
		pro[p] = { l,g };
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (str == "add") {
			int p, l, g;
			cin >> p >> l >> g;
			s[g][l].insert(p);
			s1[l].insert(p);
			pro[p] = { l,g };
		}

		else if (str == "recommend") {
			int g, x;
			cin >> g >> x;
			if (x == 1) {
				for (int j = 100; j >= 0; j--) {
					if (s[g][j].empty())	continue;
					cout << *(prev(s[g][j].end())) << '\n';
					break;
				}
			}
			else {
				for (int j = 0; j < 101; j++) {
					if (s[g][j].empty())	continue;
					cout << *s[g][j].begin() << '\n';
					break;
				}
			}

		}

		else if (str == "recommend2") {
			int x;
			cin >> x;
			if (x == 1) {
				for (int j = 100; j >= 0; j--) {
					if (s1[j].empty())	continue;
					cout << *(prev(s1[j].end())) << '\n';
					break;
				}
			}
			else {
				for (int j = 0; j <= 100; j++) {
					if (s1[j].empty())	continue;
					cout << *s1[j].begin() << '\n';
					break;
				}
			}
		}

		else if (str == "recommend3") {
			int x, l;
			cin >> x >> l;
			int res = -1;
			if (x == 1) {
				for (int j = l; j <= 100; j++) {
					if (s1[j].empty())	continue;
					res = *s1[j].begin();
					break;
				}
			}
			else {
				for (int j = l-1; j >0; j--) {
					if (s1[j].empty())	continue;
					res = *(prev(s1[j].end()));
					break;
				}
			}
			cout << res << '\n';
		}

		else if (str == "solved") {
			int a;
			cin >> a;
			s1[pro[a].first].erase(a);
			s[pro[a].second][pro[a].first].erase(a);
		}

	}

}