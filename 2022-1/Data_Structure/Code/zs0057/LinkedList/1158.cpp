#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	int arr[5001] = {};
	int index = 0;
	int n, k;
	cin >> n >> k;
	list<int> li;
	auto it = li.begin();

	for (int i = 1; i <= n; i++) {
		li.insert(it, i);
	}

	while (!(li.empty())) {
		for (int i = 0; i < k; i++) {;
			if (it == li.end())
				it = li.begin();
			it++;
		}
		it--;
		arr[index] = *it;
		index++;
		it = li.erase(it);
		
	}
	cout << '<';
	for (int i = 0; i < n-1; i++) {
		cout << arr[i] << ',' << ' ';
	}
	cout << arr[n - 1] << '>';
}