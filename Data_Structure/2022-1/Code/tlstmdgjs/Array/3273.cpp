#include<bits/stdc++.h>
using namespace std;

int a[1000001] = {};
bool occur[2000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int x;
	cin >> x;

	int freq = 0;

	for (int i = 0; i < n; i++) {
		if (x-a[i] > 0 && occur[x - a[i]])
			freq++;
		occur[a[i]] = true;
	}
	cout << freq;
}
	