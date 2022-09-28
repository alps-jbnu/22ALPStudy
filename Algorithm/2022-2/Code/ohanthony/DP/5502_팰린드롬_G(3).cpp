#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int n;
string alpha;
int dp[5005][5005];

int func(int st, int en){
    if(st >= en) return 0;

    int &ret = dp[st][en];
    if(ret != -1) return ret; // 이미 방문했고, 결과가 있으면 그걸 사용한다는 것

    ret = 0;
    if(alpha[st] == alpha[en]) ret += func(st + 1, en - 1); // 양 끝 값이 같은 경우 안쪽으로 탐색
    else ret += min(func(st+1, en), func(st, en-1)) + 1; // 양 끝 값이 다를 경우 한쪽 맞춰보고 그 중에서 작은 값 선택
    
    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> alpha;
    memset(dp, -1, sizeof(dp));
    cout << func(0, n-1) << '\n';
    return 0;
}