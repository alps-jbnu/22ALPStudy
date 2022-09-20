#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

unordered_map<string, int> s; // 학번에 000001이런식이 될 수 있으니까 key의 자료형은 string으로 해야한다.
vector<pair<string, int>> v;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.Y < b.Y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, l;
	cin >> k >> l; 
	// k: 수강 가능 인원, l: 버틀 클릭한 순서를 기록한 대기목록

	for (int i = 0; i < l; i++) {
		string num;
		cin >> num;

		s[num] = i; // map 특징으로 중복된 값을 갱신시켜 준다
	}

	for (auto i : s) v.push_back(i); // vector에 옮겨 담는다
	sort(v.begin(), v.end(), compare); 

	int count = 0;
	for (auto i : v) {
		cout << i.X << "\n";
		count++;
		if (count == k) break;
	}

	return 0;
}