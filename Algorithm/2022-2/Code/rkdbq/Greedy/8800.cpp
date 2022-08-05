#define from first.first
#define to first.second
#define box second

#include <iostream>
#include <algorithm>
using namespace std;

int n, c, m;
pair<pair<int, int>, int> town[101];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> c;
	cin >> m;
	for (int i{}; i < m; i++) {
		cin >> town[i].from >> town[i].to >> town[i].box;
	}
	sort(town, town + m, greater<>());
	for (int i{}; i < n; i++) {
		
	}

	return 0;
}