#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int arr[10] = {};

	for (int i= 0; i< s.size(); i++) {
		arr[s[i] - '0']++;
	}

	int num = 0;
	for (int i = 0; i < 10; i++) {
		if (i != 9 && i != 6)
			num = max(num, arr[i]);
	}
	cout << max(num, (arr[6] + arr[9] + 1) / 2);
	return 0;
}
	