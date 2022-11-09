#include<bits/stdc++.h>
using namespace std;

int arr[10005];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a; ++arr[a];
	}
	for (int i = 1; i <= 10000; i++) {
		while (arr[i] != 0) {
			cout << i << '\n';
			--arr[i];
		}
	}
	
}
