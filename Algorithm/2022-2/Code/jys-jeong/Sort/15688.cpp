#include<bits/stdc++.h>
using namespace std;

int arr[2000005];

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a + 1000000]++;
	}
	for (int i = 0; i <= 2000000; i++) {
		
		while (arr[i] != 0) {
			cout << i-1000000 << '\n';
			--arr[i];
		}
	}
	
}
