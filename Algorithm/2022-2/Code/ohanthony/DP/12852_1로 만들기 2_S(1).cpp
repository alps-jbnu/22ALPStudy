#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int d[1000005];
int route[1000005]; // 경로 복원 테이블

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    d[1] = 0;
    for(int i = 2; i <= n; i++){
        d[i] = d[i-1] + 1;
        route[i] = i-1; // 점화식: i->i-1로 가는게 최적
        if(i % 2 == 0 && d[i] > d[i/2] + 1) {
            d[i] = d[i/2]+1;
            route[i] = i/2;
        }
        if(i % 3 == 0 && d[i] > d[i/3] + 1){
            d[i] = d[i/3]+1;
            route[i] = i/3;
        }
    }

    cout << d[n] << '\n';
    while(n != 1){
        cout << n << ' ';
        n = route[n];
    }
    cout << '1';
    return 0;
}