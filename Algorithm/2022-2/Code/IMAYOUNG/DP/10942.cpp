#include <iostream>
#include <vector>
//10942 - 팰린드롬?
using namespace std;

vector<int> v;
int s, e;
int dp[2001][2001] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	//길이 1일때 모두 팰린드롬, dp배열에 1저장
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
	}
	//길이 2 첫 번째 수, 두 번째 수 비교
	for (int i = 1; i < N; i++) {
		if(v[i] == v[i+1]) //첫번째 수와 두번째 수가 같을 때
			dp[i][i + 1] = 1;
	}
	//길이 3일 때 양 끝의 수..
	for (int i = 2; i < N; i++) { //length
		for (int j = 1; j <= N-i; j++) { //left
			if (v[j] == v[i + j] && dp[j + 1][i + j - 1])
				dp[j][i + j] = 1;
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s,e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}

	return 0;
}