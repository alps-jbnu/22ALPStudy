#include <bits/stdc++.h>

using namespace std;

int N, M;
int num[2002];
int answer[2002][2002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    for (int start = N; start >= 1; start--) {
        answer[start][start] = 1;
        for (int end = start + 1; end <= N; end++) {
            if (num[start] == num[end]) {
                if (answer[start + 1][end - 1] || abs(start - end) == 1) answer[start][end] = 1;
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int S, E; cin >> S >> E;
        cout << answer[S][E] << "\n";
    }
    return 0;
}