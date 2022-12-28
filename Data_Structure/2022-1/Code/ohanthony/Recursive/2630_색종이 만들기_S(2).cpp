#include<bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int board[130][130];
int blue, white;

void func(int x, int y, int n) {
    bool isWhite = true;
    bool isBlue = true;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[i][j] == 1) isWhite = false;
            else isBlue = false;
        }
    }

    if (isWhite) {
        white++;
        return;
    }
    if (isBlue) {
        blue++;
        return;
    }

    func(x, y, n / 2);
    func(x, y + n / 2, n / 2);
    func(x + n / 2, y, n / 2);
    func(x + n / 2, y + n / 2, n / 2);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < n; ii++) cin >> board[i][ii];
    }

    func(0, 0, n);
    cout << white << '\n' << blue;
    return 0;
}