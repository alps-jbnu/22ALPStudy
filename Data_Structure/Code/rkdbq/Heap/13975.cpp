#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int j{}; j < T; j++) {
		int K;
		cin >> K;

		priority_queue<long long, vector<long long>, greater<long long>> files; //long long
		long long ans{};

		for (int i{}; i < K; i++) {
			int file;
			cin >> file;
			files.push(file);
		}

		while (true) {
			if (files.size() == 1) break;

			long long combinedfile{};

			combinedfile += files.top();
			files.pop();
			combinedfile += files.top();
			files.pop();

			ans += combinedfile;
			files.push(combinedfile);
		}

		cout << ans << "\n";
	}
	return 0;
}