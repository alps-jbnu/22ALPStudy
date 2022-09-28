#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, sum = 0, result = 0;
	vector<int> vec;
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());


	for (int i = 0; i < n; i++) {
		sum += vec[i];
		result += sum;
	}
	cout << result << endl;
	return 0;
}