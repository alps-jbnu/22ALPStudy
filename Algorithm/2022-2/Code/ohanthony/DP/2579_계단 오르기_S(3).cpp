#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

/*
(2차원 배열로 테이블 정의)
d[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 
점수 합의 최댓값, 단 i번째 계단은 반드시 밟아야 함
*/
int stairs[303]; // i번째 계단에 쓰여 있는 점수를 의미
int d[303][3];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> stairs[i];
    if (n == 1) {
        cout << stairs[1];
        return 0;
    }

    d[1][1] = stairs[1];
    d[1][2] = 0;
    d[2][1] = stairs[2];
    d[2][2] = stairs[1] + stairs[2];

    for (int i = 3; i <= n; i++) {
        // 1개의 계단을 연속해서 밟는다 == 지금 밟고 있는 계단 (이전 계단을 밟고있지 않으니까 i-2가 맞다)
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + stairs[i]; 

        // 2개의 계단을 연속해서 밟고 있다 == 지금 밟고 있는 계단(1) + 이전의 계단(1, i-1)
        d[i][2] = d[i - 1][1] + stairs[i];
    }

    cout << max(d[n][1], d[n][2]);
    return 0;
}