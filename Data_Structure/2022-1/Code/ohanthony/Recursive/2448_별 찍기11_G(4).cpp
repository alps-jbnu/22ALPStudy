#include<bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second
const int MAX = 1024 * 3 + 5;

char board[MAX][2 * MAX - 1];

void print_star(int x, int y) {
    board[x][y] = '*'; // 첫 번째 줄 *

    board[x + 1][y - 1] = '*'; // 두 번째 줄 * *
    board[x + 1][y + 1] = '*';

    // 세 번째 줄 *****
    for (int i = 0; i < 5; i++) board[x + 2][y - 2 + i] = '*';
}

void triangle(int len, int x, int y) {
    if (len == 3) { // base condition
        print_star(x, y);
        return;
    }

    int half = len / 2;
    triangle(half, x, y); // 첫 번째 삼각형의 꼭지점
    triangle(half, x + half, y - half); // 두 번째 삼각형의 꼭지점
    triangle(half, x + half, y + half); // 세 번째 삼각형의 꼭지점
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < 2 * n - 1; ii++) {
            board[i][ii] = ' ';
        }
    }

    triangle(n, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < 2 * n - 1; ii++) {
            cout << board[i][ii];
        }
        cout << '\n';
    }

    return 0;
}