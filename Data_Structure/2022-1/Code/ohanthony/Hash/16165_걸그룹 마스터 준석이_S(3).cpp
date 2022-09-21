#include<bits/stdc++.h>
using namespace std;

int n, m, num, category; // num: 그룹 인원 수, category: 퀴즈 유형
string group, quez; // group: 그룹 이름, quez: 퀴즈

unordered_map<string, string> mTOg;			// key: 멤버 이름, value: 그룹 이름
unordered_map<string, vector<string>> gTom; // key: 그룹 이름, value: 멤버 이름
// map은 중복을 허용하지 않지만 value에 여러개의 값을 두고 싶을 때 vector 사용

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	// n개의 입력 받을 걸그룹의 수
	while (n--) {
		cin >> group >> num;

		while (num--) {
			string member; // 멤버 이름
			cin >> member;

			mTOg[member] = group;
			gTom[group].push_back(member);
		}
		sort(gTom[group].begin(), gTom[group].end()); // 사전 순으로 나열
	}

	// m개의 퀴즈 입력
	while (m--) {
		cin >> quez >> category;

		if (category == 0) for (auto i : gTom[quez]) cout << i << "\n";
		else cout << mTOg[quez] << "\n";
	}
	
	return 0;
}