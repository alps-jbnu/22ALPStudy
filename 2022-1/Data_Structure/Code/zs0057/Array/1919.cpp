#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	string a, b;
	int cnt = 0;
	int arr[26] = {};
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		arr[a[i] - 'a']++;
	}
	for (int i = 0; i < b.length(); i++) {
		arr[b[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] < 0) {
			cnt += -arr[i];
		}
		else
			cnt += arr[i];
	}
	cout << cnt;
}

