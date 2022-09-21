#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
long long ans=0;
int n;
long long m;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	int st = 0;
	int en = 0;
	long long g = 0x7fffffff;
	while (st <= en) {
		if (st >=n)	break;
		if (en == n-1) {
			if(vec[en]-vec[st]>=m)	g = min(g, vec[en] - vec[st]);
			++st;
			continue;
		}

		if (vec[en] - vec[st] >= m) {
			g = min(g, vec[en] - vec[st]);
			++st;
		}
		else {
			++en;
		}
	}
	cout << g;
}
