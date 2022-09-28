#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[5005];
int d[5005][5005];


void func(int s, int e) {
    if (s == e) return;
    if (s > e) return;
    if (d[s][e])    return;
    if (arr[s] == arr[e]) {
        func(s + 1, e - 1);
        d[s][e] = d[s + 1][e - 1];
    }
    else {
        func(s + 1, e);
        func(s, e - 1);
        d[s][e] = min(d[s + 1][e]+1, d[s][e - 1]+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    func(1, n);

    cout << d[1][n];
}