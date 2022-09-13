#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> p[1005];
int a=INT_MAX, b=INT_MIN;
int cnt[1000005];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
		a = min(a, p[i].first);
		b = max(b,p[i].second);
		for (int st = p[i].first+1; st <= p[i].second; st++) {
			cnt[st]++;
		}
	}
	int en=0;
	int st=0;
	int sm = 0;
	vector<pair<int, int>> vec;
	while(st<=b&&en<=b){
		

		if (sm == k) {
			cout << st << ' ' << en;
			return 0;
		}
		else if (sm < k) {
			sm += cnt[++en];
			
		}
		else {
			sm -= cnt[++st];
			
		}
	}
	cout << 0 << ' ' << 0;
	
}
