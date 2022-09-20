#include<bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	int m;
	cin >> m;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		cout << binary_search(vec.begin(),vec.end(),a)<<'\n';
	}
}
