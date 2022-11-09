#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff

int arr[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, count = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int sum = arr[0];
    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && sum != m) {
            if (sum > m) break; // sum > m인 경우 조건을 만족하지 않는다
            en++;
            if (en != n) sum += arr[en];
        }
        if (sum > m) {         // sum == m인 경우만 찾는거니까 sum > m인 경우 구간 설정 초기화 시킨다
            sum = arr[st + 1]; // sum도 st시작점 기준으로 다시 설정
            en = st + 1;       // en도 마찬가지로 다음 st로 설정      
            continue;
        }
        if (sum == m) {
            count++;
            sum = arr[st + 1];
            en = st + 1;
            continue;
        }
        if (en == n) break;
    }

    cout << count;
    return 0;
}