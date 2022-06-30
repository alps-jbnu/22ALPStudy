#include<bits/stdc++.h>
using namespace std;

int spot[100002];

int main() {
	int subin, brother;
	cin >> subin >> brother;
	fill(spot, spot + 100001, -1);
	spot[subin]=0;
	queue<int> q;
	q.push(subin);
	while (!q.empty()||spot[brother]==-1) {
		int dot = q.front();
		q.pop();
		for (int k : {dot + 1, dot - 1, 2 * dot}) {
			if (k < 0 || k>100001)	continue;
			if (spot[k] != -1)	continue;
			spot[k] = spot[dot] + 1;
			q.push(k);
		}
	}
	cout << spot[brother];
}