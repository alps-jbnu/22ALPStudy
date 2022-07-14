#include<bits/stdc++.h>
using namespace std;

int cnt[1000001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int f, s, g, u, d;
int main() {
	cin >> f >> s >> g >> u >> d;
	queue<int> q;
	q.push(s);
	fill(cnt+1, cnt + f+1, -1);
	cnt[s] = 0;
	while (!q.empty()&&cnt[g]==-1) {
		int dot = q.front();
		q.pop();
		for (int k : {u + dot,  dot-d}) {
			if (k <= 0 || k > f)	continue;
			if (cnt[k] > -1)	continue;
			cnt[k] = cnt[dot] + 1;
			q.push(k);
		}
	}
	if (cnt[g] != -1) {
		cout << cnt[g];
	}
	else {
		cout << "use the stairs";
	}
}