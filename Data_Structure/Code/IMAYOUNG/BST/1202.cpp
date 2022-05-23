#include <bits/stdc++.h>
using namespace std;

int N, K, C;
pair <int, int> arr[300001];
int bag[300001];
bool vis[300001] = { false };
long long ans = 0;
pair<int, int> item;

long long solve() {
	long long res =0;
	int idx = 0;
	priority_queue <int> pq;
	for (int i = 0; i < K; i++) {
		while (idx < N && bag[i] >= arr[idx].first) {
			pq.push(arr[idx++].second);
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}
	sort(arr, arr + N);
	sort(bag, bag + K);
	cout << solve();
}