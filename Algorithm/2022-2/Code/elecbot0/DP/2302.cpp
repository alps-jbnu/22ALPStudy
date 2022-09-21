#include <bits/stdc++.h>

using namespace std;

int N, M;
int fxd[50];
int answer[50];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int temp; cin >> temp;
        fxd[temp] = 1;
    }
    answer[0] = 1; answer[1] = 1;
    int total_answer = 1;
    for (int i = 2; i <= N; i++) {
        if (fxd[i] || fxd[i - 1]) {
            total_answer *= answer[i - 1];
            answer[i] = 1;
            continue;
        }
        answer[i] = answer[i - 1] + answer[i - 2];
    }
    total_answer *= answer[N];
    cout << total_answer;
    return 0;
}