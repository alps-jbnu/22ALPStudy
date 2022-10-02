#include <bits/stdc++.h>

using namespace std;

int n, m;
int answer[1002][1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int max_answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char read; cin >> read;
            answer[i][j] = read - '0';
            max_answer = max(max_answer, answer[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (answer[i][j] && answer[i - 1][j] && answer[i][j - 1] && answer[i - 1][j - 1]) {
                answer[i][j] = min({answer[i - 1][j], answer[i][j - 1], answer[i - 1][j - 1]}) + 1;
                max_answer = max(max_answer, answer[i][j]);
            }
        }
    }
    cout << max_answer * max_answer;
    return 0;
}