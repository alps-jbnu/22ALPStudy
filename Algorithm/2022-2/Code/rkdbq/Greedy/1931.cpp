#define startc first
#define endc second

#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<long long ,long long> conf[100001];
long long curEnd, cnt;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.endc != b.endc) return a.endc < b.endc;
	else return a.startc < b.startc;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		cin >> conf[i].startc;
		cin >> conf[i].endc;
	}
	sort(conf, conf + N, cmp);
	for (int i{}; i < N; i++) {
		if (curEnd <= conf[i].startc) {
			curEnd = conf[i].endc;
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}