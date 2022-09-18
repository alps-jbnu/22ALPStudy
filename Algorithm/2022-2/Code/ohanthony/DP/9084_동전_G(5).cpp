#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int T, N, M;
/*
- T: 테스트 케이스 개수
- N: 동전의 가지 수
- M: 동전으로 만들어야 하는 금액
- coin: 동전 금액
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--){
        int dp[10005] = {0, }; // 테이블 정의: 0~10005원을 만들 수 있는 방법
        int coin[25] = {0, };
        cin >> N;
        for(int i = 1; i <= N; i++) cin >> coin[i];

        cin >> M;  // 동전으로 만들어야 하는 금액
        dp[0] = 1; // 0원을 만들 수 있는 방법 1개
        for(int i = 1; i <= N; i++){
            for(int j = coin[i]; j <= M; j++){
                // 점화식: 가장 마지막에 해당 동전을 사용해서 금액을 완성시키는 과정
                dp[j] = dp[j] + dp[j - coin[i]]; //dp[j - coin[i]]: j - coin[i]을 만들 수 있는 방법의 수
            }
        }
        cout << dp[M] << '\n';
    }
    return 0;
}