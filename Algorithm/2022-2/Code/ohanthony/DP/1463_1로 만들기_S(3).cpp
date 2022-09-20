#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int arr[1000005];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    arr[1] = 0;
    for(int i = 2; i <= n; i++){ // 점화식
        arr[i] = arr[i-1]+1;
        if(i%2 == 0) arr[i] = min(arr[i], arr[i/2]+1);
        if(i%3 == 0) arr[i] = min(arr[i], arr[i/3]+1);
    }
    cout << arr[n];
    return 0;
}

/*
(테이블 정의)
: d[i] = i를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값
*/