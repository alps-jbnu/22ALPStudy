#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100002];
long long num, cnt;
long long ansNum, ansCnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	num = arr[0];
	for (int i{}; i < N; i++) {
		if (arr[i] == num) cnt++;
		else {
			if (ansCnt < cnt) {
				ansCnt = cnt;
				ansNum = num;
			}
			num = arr[i];
			cnt = 1;
		}
	}
	if (ansCnt < cnt) {
		ansCnt = cnt;
		ansNum = num;
	}
	cout << ansNum << "\n";
	return 0;
}