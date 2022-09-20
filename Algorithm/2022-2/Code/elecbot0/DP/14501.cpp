#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> schedule;
int answer[20];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int T, P; cin >> T >> P;
        schedule.push_back(make_pair(T, P));
    }
    int m = 0;
    for (int i = 0; i < N; i++) {
        int cur = 0;
        for (int j = 0; j < i; j++) {
            if (schedule[j].first + j <= i) {
                cur = max(cur, answer[j]);
            }
        }
        if (schedule[i].first + i <= N) {
            cur += schedule[i].second;
        }
        answer[i] = cur;
        m = max(m, answer[i]);
    }
    cout << m;
    return 0;
}