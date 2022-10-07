#include <bits/stdc++.h>

using namespace std;

#define MODULO 10007

int n;
int arr[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr[1] = 1; arr[2] = 3;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] * 2;
        if (arr[i] >= MODULO) {
            arr[i] %= MODULO;
        }
    }
    cout << arr[n];
    return 0;
}