#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> v;
bool vis[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != tmp) {
			v.push_back(arr[i]);
			tmp = v[cur];
			func(cur+1);
			v.pop_back();
		}
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
	
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (tmp != arr[i]) {
			v.push_back(arr[i]);
			tmp = v[0];
			func(1);
			v.pop_back();
		}
	}
	
 }