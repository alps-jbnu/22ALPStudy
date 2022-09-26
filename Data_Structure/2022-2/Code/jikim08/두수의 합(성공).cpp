#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int len;
	cin >> len;
	int* arr = new int[len];

	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + len);
	int x;
	
	cin >> x;
	int a = 0, b = len - 1, cnt = 0;

	while (a < b) {
		if (arr[a] + arr[b] == x) {
			cnt++;
			a += 1;
			b -= 1;
		}
		else if (arr[a] + arr[b] > x) {
			b -= 1;
		}
		else if (arr[a] + arr[b] < x) {
			a += 1;
		}
	}

	cout << cnt;

}
