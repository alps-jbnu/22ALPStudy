#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> v;
bool vis[10];

void func(int cur,int num) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i < n; i++) {
		if (vis[i])	continue;
		v.push_back(arr[i]);
		vis[i] = 1;
		func(cur + 1,i+1);
		vis[i] = 0;
		v.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
		vis[i] = 1;
		func(1,i+1);
		v.pop_back();
		vis[i] = 0;
	}
}