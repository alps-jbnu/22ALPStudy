#include <bits/stdc++.h>

using namespace std;

vector<int> idx;
int dp[2001][2001]{};

void Rec(int s, int e)
{
	if (dp[s][e]>0) return; //dp내에 결과가 이미 있을때 pass
	if (e - s < 2) {
		 if(idx[s - 1] == idx[e - 1]) dp[s][e] = 2;
		 else dp[s][e] = 1;
		 dp[s][s] = 2;
		 dp[e][e] = 2; //s와 e가 같을때의 경우 무조건 팰린드롬
		 return;
	} //idx[s]와 idx[e]가 같은경우는 무조건 팰린드롬 (s와 e차이가 1이하일때)
	Rec(s + 1, e);
	Rec(s, e - 1); //양 끝의 기준점을 하나씩 줄여가며 dp실행 (복잡도 n^2)
	if (dp[s + 1][e - 1]==2 && idx[s - 1] == idx[e - 1]) dp[s][e] = 2; // s,e의 idx가 같으면서 dp배열내 s+1,e-1막대가 팰린드롬이어야 dp[s][e]도 팰린드롬
	else dp[s][e] = 1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n, q, cnt;
	cin >> n;
	cnt = n;
	while (cnt--)
	{
		int t; cin >> t;
		idx.push_back(t);
	}
	Rec(1, n);
	cin >> q;
	while (q--)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e]-1 << "\n";
	}
}