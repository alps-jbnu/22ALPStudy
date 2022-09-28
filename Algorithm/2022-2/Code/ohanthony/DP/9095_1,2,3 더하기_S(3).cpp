#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int arr[15];
int t;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 1,2,3 을 이용해 각각 1, 2, 3을 만드는 경우의 수, 테이블을 미리 작성
    arr[1] = 1; 
    arr[2] = 2;
    arr[3] = 4; // 1+2, 2+1, 3, 1+1+1 이렇게 4가지 경우
    for(int i = 4; i < 11; i++) arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << arr[n] << "\n";
    }
    return 0;
}
