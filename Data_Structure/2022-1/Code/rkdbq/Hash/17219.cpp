#include <iostream>
#include <unordered_map>
using namespace std;

int T, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int j{}; j < T; j++) {
		unordered_map<string, int> clothes;
		int ans{ 1 };
		cin >> N;
		for (int i{}; i < N; i++) {
			string cate, clo;
			cin >> clo >> cate;
			clothes[cate]++;
		}

		for (auto i{ clothes.begin() }; i != clothes.end(); i++) {
			ans *= ++(*i).second;
		}
		cout << ans - 1 << "\n";
	}
	return 0;
}