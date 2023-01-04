#include<bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

string video[65];

void compression(int x, int y, int n) {
    if (n == 1) {
        cout << video[x][y];
        return;
    }

    bool isZero = true;
    bool isOne = true;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (video[i][j] == '1') isZero = false;
            else isOne = false;
        }
    }

    if (isZero) cout << '0';
    else if (isOne) cout << '1';
    else {
        cout << "(";
        compression(x, y, n / 2);
        compression(x, y + n / 2, n / 2); // 순서 잘 확인하기
        compression(x + n / 2, y, n / 2);
        compression(x + n / 2, y + n / 2, n / 2);
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> video[i];
    compression(0, 0, n);
    return 0;
}