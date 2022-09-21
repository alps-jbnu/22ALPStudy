#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		unordered_map<string, int> fashion;
		int n, result = 1;
		cin >> n;
		while (n--) {
			string name, cloth;
			cin >> name >> cloth;
			
			if (fashion.find(cloth) != fashion.end()) fashion[cloth] += 1;
			else fashion[cloth] = 1;
		}

		for (auto its = fashion.begin(); its != fashion.end(); its++) {
			result *= its->second + 1;
		}

		cout << result - 1 << "\n";
	}
	return 0;
}