#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
bool vis[100005];
long long cnt = 0;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vis[arr[0]] = 1;
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n - 1 && !vis[arr[en + 1]]) {
			en++;
			vis[arr[en]] = 1;
		}
		cnt += en - st + 1;
		vis[arr[st]] = 0;
	}
	cout << cnt;
}
