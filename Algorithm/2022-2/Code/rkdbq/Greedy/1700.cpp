#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, K;
int use[202];
multiset<int> cur;
multiset<int> nxt;
set<int> nxtEle;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	
	int startIdx{}, nxtIdx{};
	for (int i{}; i < K; i++) {
		cin >> use[i];
		if (cur.size() < N){
			if (cur.find(use[i]) == cur.end()) {
				cur.insert(use[i]);
				startIdx = i + 1;
			}
		}
		else if (nxtEle.size() < N) {
			nxt.insert(use[i]);
			nxtEle.insert(use[i]);
			nxtIdx = i;
		}
	}
	for (int i{ startIdx }; i < K; i++) {
		int tempCnt{ -1 }, tempEle{ -1 };
		if (cur.find(use[i]) == cur.end()) {
			for (auto it{ cur.begin() }; it != cur.end(); it++) {
				if (tempCnt >= nxt.count(*it)) {
					tempCnt = nxt.count(*it);
					tempEle = *it;
				}
			}
			cur.erase(cur.find(tempEle));
			cur.insert(use[i]);
			ans++;
		}
		nxt.erase(nxt.find(use[i]));
		if (nxt.find(use[i]) == nxt.end()) nxtEle.erase(use[i]);
		while (true) {
			if (nxtIdx >= K - 1) break;
			if (nxtEle.size() >= N && nxt.find(use[nxtIdx + 1]) == nxt.end()) break;
			nxtIdx++;
			nxt.insert(use[nxtIdx]);
			nxtEle.insert(use[nxtIdx]);
		}		
	}
	cout << ans << "\n";

	return 0;
}