#include<bits/stdc++.h>
using namespace std;


vector<int> vec[100001];
int num[100001];
int main() {
	
	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int a : vec[now]) {
			if (num[now] == a)	continue;
			num[a] = now;
			q.push(a);
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << num[i] << "\n";
	}
}