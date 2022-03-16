#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
stack<int> stck;
vector<int> vec;
vector<char> ans;
int pushCnt{ 1 }, popCnt;

int chk() {
	int idx{};
	while (popCnt != n) {
		if (stck.empty() || vec[idx] > stck.top()) {
			stck.push(pushCnt++);
			ans.push_back('+');
		}
		else if (vec[idx] < stck.top()) {
			//cout << "NO" << "\n";
			return 1;
		}
		else {
			stck.pop();
			ans.push_back('-');
			idx++;
			popCnt++;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{ 1 }; i <= n; i++) {
		int input;
		cin >> input;
		vec.push_back(input);
	}
	
	if(chk()) cout << "NO\n";
	else {
		for (int i{}; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
}