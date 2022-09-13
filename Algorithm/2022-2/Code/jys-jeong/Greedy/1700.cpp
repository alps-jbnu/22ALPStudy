#include <bits/stdc++.h>
using namespace std;

int arr[102];
int n, k;
bool vis[102];
vector <int> vec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) {
		if (vis[arr[i]])	continue;
		else if (vec.size() < n) {
			vec.push_back(arr[i]);
			vis[arr[i]] = 1;
		}
		else {
			
			vector<pair<int, int>> d;
			for (int x = 1; x <= k; x++) {
				if (!vis[x])	continue;
				bool vis = false;
				for (int y = i + 1; y <= k; y++) {
					if (arr[y] == x) {
						d.push_back({ y,x });
						vis = 1;
						break;
					}
				}
				if (!vis)	d.push_back({ k + 1,x });
			}
			sort(d.begin(), d.end(), greater<pair<int, int>>());
			vis[d[0].second] = false;
			++cnt;
			vis[arr[i]] = true;
		}
	}
	cout << cnt;
}