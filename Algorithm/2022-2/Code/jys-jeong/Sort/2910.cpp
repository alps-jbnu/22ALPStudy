#include<bits/stdc++.h>
using namespace std;


int n;
long long m;
vector<pair<int,int>> vec;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a ;
		bool c = 0;
		for (auto& k : vec) {
			if (a == k.first) {
				c = 1;
				k.second++;
 				break;
			}
		}
		if (!c) {
			vec.push_back({ a,1 });
		}
	}
	stable_sort(vec.begin(), vec.end(), compare);
	
	int sz = vec.size();
	for (int i = 0; i < sz; i++) {
		while (vec[i].second != 0) {
			cout << vec[i].first << ' ';
			--vec[i].second;
		}
	}
}
