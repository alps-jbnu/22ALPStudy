#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	int n;
	cin >> n;
	string a, b;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a == b) {
			cout << "Possible" << '\n';
		}
		else {
			cout << "Impossible" << '\n';
		}
	}
}
