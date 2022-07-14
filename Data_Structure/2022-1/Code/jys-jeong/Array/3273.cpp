#include<bits/stdc++.h>
using namespace std;

int num[100001];
bool vis[2000001];
int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int cnt = 0;
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (x - num[i] > 0 && vis[x - num[i]]) {
			++cnt;
		}
		vis[num[i]] = true;
	}
	cout << cnt;
}