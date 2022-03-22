#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
	string s;
	cin >> s;

	int arr[10] = {};


	for (auto ch : s) {
		arr[ch - '0']++;
	}
	arr[6] = (arr[6] + arr[9] + 1) / 2;
	arr[9] = 0;

	int maxVal = arr[0];
	for (int i = 0; i <= 9; i++) {
		maxVal = max(arr[i], maxVal);
	}
	cout << maxVal;

}