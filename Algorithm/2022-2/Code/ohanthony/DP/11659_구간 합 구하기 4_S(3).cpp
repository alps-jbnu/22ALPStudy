#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int num[100005];
int d[100005];
int N, M, i, j;
/*
- N: 수의 개수
- M: 합을 구해야 하는 횟수
- i~j: 구간 i와 j
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int x = 1; x <= N; x++) cin >> num[x];

    d[1] = num[1]; // 테이블 정의: 해당 index까지의 누적 합
    for(int x = 2; x <= N; x++){
        d[x] = d[x-1] + num[x]; // 점화식
    }

    while(M--){ // dp로 접근 안하면 이중 for문 구간에서 100000 x 100000 으로 시간초과가 발생. 즉, 이 구간에 들어가전에 점화식을 미리 구해놓고 접근
        int sum = 0;
        cin >> i >> j;
        // cout << d[j]-d[i]+num[i] << '\n';
        cout << d[j] - d[i-1] << '\n';
    }
    return 0;
}