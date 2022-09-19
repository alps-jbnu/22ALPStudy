#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int n; // 집의 수
int d[1005][3]; // [i][3]: 0(R), 1(G), 2(B) 
int R[1005], G[1005], B[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> R[i] >> G[i] >> B[i];

    d[1][0] = R[1];
    d[1][1] = G[1];
    d[1][2] = B[1];

    for(int i = 2; i <= n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + R[i];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + G[i];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + B[i];
    }

    cout << min({d[n][0], d[n][1], d[n][2]});
    return 0;
}