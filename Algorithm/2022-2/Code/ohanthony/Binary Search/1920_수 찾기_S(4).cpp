#include<bits/stdc++.h>
using namespace std;

int arr[100005];
int n, m;

int func(int num) {
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == num) return 1;
		else if (arr[mid] > num) end = mid-1;
		else if (arr[mid] < num) start = mid+1;
	}
	return 0; // start > end 인 경우 while문 탈출
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n, m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << func(num) << '\n';
	}
	return 0;
}

