#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int N, M;
string map[11];
vector<string> godStr;
int dx[8]{ 0,1,0,-1,1,1,-1,-1 };
int dy[8]{ 1,0,-1,0,1,-1,1,-1 };
int K;

unordered_map<string, long long> ans;
string cur;

void dfs(int curX, int curY) {
	cur += map[curX][curY];
	ans[cur]++;
	//cout << cur << "\n";

	if (cur.length() == 5) return;
		
	for (int i{}; i < 8; i++) {
		int nxtX{ curX + dx[i] };
		int nxtY{ curY + dy[i] };
		if (nxtX >= N) nxtX = 0;
		else if (nxtX < 0) nxtX = N - 1;
		if (nxtY >= M) nxtY = 0;
		else if (nxtY < 0) nxtY = M - 1;
		dfs(nxtX, nxtY);
		cur.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i{}; i < N; i++) {
		cin >> map[i];
	}
	for (int i{}; i < K; i++) {
		string str;
		cin >> str;
		godStr.push_back(str);
	}
	for (int i{}; i < N; i++) {
		for (int j{}; j < M; j++) {
			cur.clear();
			dfs(i, j);
		}
	}
	for (auto it{ godStr.begin() }; it != godStr.end(); it++) {
		cout << ans[*it] << "\n";
	}
	
	return 0;
}