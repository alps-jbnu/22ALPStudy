#define open first
#define close second

#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> flower[100001];
int befClose{ 301 }, cnt;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.close == b.close) return a.open < b.open;
	else return a.close > b.close;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		int month, date;
		cin >> month >> date;
		flower[i].open = month * 100 + date;
		cin >> month >> date;
		flower[i].close = month * 100 + date;
	}
	sort(flower, flower + N, cmp);
	/*for (int i{}; i < N; i++) {
		cout << flower[i].open << " " << flower[i].close << "\n";
	}*/
	for (int i{}; i < N; i++) {
		if (befClose > 1130) break;
		if (befClose >= flower[i].open && befClose < flower[i].close) {
			//cout << "add " << flower[i].open << " " << flower[i].close << "\n";
			befClose = flower[i].close;
			cnt++;
			i = -1;
		}
	}
	if (befClose > 1130) cout << cnt << "\n";
	else cout << 0 << "\n";
	return 0;
}