#define freq second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N, C;
pair<int, pair<int, int>> p[1001]; //value, freq, appear
map<string, pair<int, int>> m;
int cnt;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.freq == b.second.freq) return a.second.first < b.second.first;
	else return a.second.freq > b.second.freq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> C;
	for (int i{}; i < N; i++) {
		int num;
		cin >> num;
		if (m[to_string(num)].first == 0) m[to_string(num)].first = ++cnt;
		m[to_string(num)].freq++;
	}
	int idx{};
	for (auto it{ m.begin() }; it != m.end(); it++) {
		for (int i{ (*it).second.freq }; i > 0; i--) {
			p[idx].first = stoi((*it).first);
			p[idx].second.freq = (*it).second.freq;
			p[idx].second.first = (*it).second.first;
			idx++;
		}
	}
	//for (int i{}; i < N; i++) cout << p[i].first << " ";
	sort(p, p + N, cmp);
	for (int i{}; i < N; i++) cout << p[i].first << " ";
	return 0;
}