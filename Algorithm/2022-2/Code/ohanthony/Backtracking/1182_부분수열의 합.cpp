#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int result;
int n, s;

int arr[30];

void func(int k, int sum){ // sum: 문제조건에서 말한 합
    if(k == n){ // base condition
        if(sum == s) result++;
        return;
    }

    func(k+1, sum);
    func(k+1, sum+arr[k]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    func(0, 0);
    if(s == 0) result--; // 문제 조건 중 크기가 양수인 부분수열만 센다고 했으므로 공집합을 제외시켜야 하는 조건
    cout << result;
    return 0;
}