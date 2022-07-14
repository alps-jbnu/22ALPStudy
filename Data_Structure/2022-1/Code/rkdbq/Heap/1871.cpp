#include <iostream>
#include <queue>
using namespace std;

long long ans;

priority_queue <pair<int, long long>> problems;
priority_queue <pair<long long, int>> candidates;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i{}; i < N; i++) {
		pair<int, long long> prob;
		cin >> prob.first >> prob.second;
		problems.push(prob);
	}

	/*for (int i{}; i < N; i++) {
		cout << problems.top().first << " " << problems.top().second << endl;
		problems.pop();
	}*/

	for (int i{ N }; i > 0; i--) {
		while (true) {
			if (problems.empty()) break;
			else if (problems.top().first >= i) {
				candidates.push({ problems.top().second, problems.top().first });
				problems.pop();
			}
			else break;
		}
		if (candidates.empty()) continue;
		ans += candidates.top().first;
		candidates.pop();
	}
	cout << ans << "\n";
	return 0;
}