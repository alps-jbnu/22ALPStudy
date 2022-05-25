#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec[51];

int root;
int cnt;

void tree(int n) {
	if (vec[n].size() == 0) {
		++cnt;
		return;
	}
	for (int k : vec[n]) {
		tree(k);
	}
}



int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a != -1)
			vec[a].push_back(i);
		else
			root = i;
	}
	cin >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == m) {
				vec[i].erase(vec[i].begin() + j);
			}
		}
	}
	if (m == root) {
		cout << "0";
		return 0;
	}
	tree(root);

	cout << cnt;
}