#include<bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> vec(101,vector<int>(0));

void com(vector<int>& vec) {
	vector<int> t(vec.size());
	copy(vec.begin(), vec.end(), t.begin());

	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for (int i = 0; i < vec.size(); i++) {
		int idx = lower_bound(t.begin(), t.end(), vec[i]) - t.begin();
		vec[i] = idx;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			vec[i].push_back(a);
		}
	}
	for (int i = 0; i < n; i++) {
		com(vec[i]);
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			if (vec[i].size() == vec[j].size()) {
				bool eq = true;
				for (int k = 0; k < vec[i].size(); k++) {
					if (vec[i][k] != vec[j][k])	eq = false;
				}
				if (eq)	ans++;
			}
		}
	}
	cout << ans;
}
