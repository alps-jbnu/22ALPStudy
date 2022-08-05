#include<bits/stdc++.h>
using namespace std;


int main() {
	int n,v;
	int num[102];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> v;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] == v)
			++cnt;
	}
	cout << cnt;
}