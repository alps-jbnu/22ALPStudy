#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N, K;
vector<int> ans;
list<int> p;
list<int>::iterator it;
void endChk() {
	if (it == p.end()) it = p.begin();
}
void josephus(int n, int k) {
	for (int i{ 1 }; i <= n; i++) {
		p.push_back(i);
	}
	it = p.begin();
	while (!p.empty()) {	
		for (int i{}; i < k - 1; i++) it++, endChk();
		ans.push_back(*it);
		it = p.erase(it);
		endChk();
	}
	cout << "<";
	for (int i{}; i < ans.size() - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[ans.size() - 1] << ">";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> K;
	josephus(N, K);
}