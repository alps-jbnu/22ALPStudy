#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	deque<int> de;
	int arr[50];
	for (int i = 1; i <= n;i++) {
		de.push_back(i);
	}
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int h;
		cin >> h;
		int idx;
		for (int j = 0; j < n; j++) {
			if (de[j] == h) {
				idx = j;
				break;
			}
		}
		if (idx <= de.size() / 2) {
			for (;;) {
				if (de.front() == h) {
					de.pop_front();
					break;
				}
				de.push_back(de.front());
				de.pop_front();
				++cnt;
			}
		}
		else{
			for (;;) {
				if (de.front() == h) {
					de.pop_front();
					break;
				}
				de.push_front(de.back());
				de.pop_back();
				++cnt;
			}
		}
	}
	cout << cnt;

}