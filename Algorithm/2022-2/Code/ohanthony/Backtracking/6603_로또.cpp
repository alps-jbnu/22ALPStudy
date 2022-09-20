#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int k;
int S[15];
int arr[15];
bool isused[15];

void func(int n) {
    if (n == 6) {
        for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < k; i++) {
        if (arr[n - 1] > S[i]) continue; // 이전 수보다 작으면 continue 실행

        if (!isused[i]) {
            isused[i] = true;
            arr[n] = S[i];
            func(n + 1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) cin >> S[i];
        sort(S, S + k);
        func(0);
        cout << '\n';

        fill(S, S + 15, 0);
        fill(arr, arr + 15, 0);
        fill(isused, isused + 15, 0); // 매 조건마다 초기화
    }
    return 0;
}