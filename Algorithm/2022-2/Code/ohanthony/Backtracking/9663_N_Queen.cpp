#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

bool isused1[40]; // 세로를 차지하고 있는지
bool isused2[40]; // / 방향 대각선을 차지하는지 여부
bool isused3[40]; // \ 방향 대각선을 차지하는지 여부

int n, result;

void func(int cur){ // cur번째 row에 말을 배치할 예정
    if(cur == n){ // base condition
        result++;
        return;
    }

    for(int i = 0; i < n; i++){
        if(isused1[i] || isused2[i+cur] || isused3[cur-i+n-1]) continue;

        isused1[i] = true;
        isused2[i+cur] = true;
        isused3[cur-i+n-1] = true;
        func(cur+1);
        isused1[i] = false;
        isused2[i+cur] = false;
        isused3[cur-i+n-1] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    func(0);
    cout << result;
    return 0;
}