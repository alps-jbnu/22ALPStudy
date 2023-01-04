#include<bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

void star(int x, int y, int n) {
    // 공백으로 출력하는 부분의 규칙
    if ((x / n) % 3 == 1 && (y / n) % 3 == 1) cout << ' ';
    else {
        if (n / 3 == 0) cout << '*';
        else star(x, y, n / 3);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < n; ii++) {
            star(i, ii, n);
        }
        cout << '\n';
    }
    return 0;
}