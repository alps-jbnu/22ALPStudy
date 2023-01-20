#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

queue<int> q;
int minTime[100005];
int postion[100005];
int n, k;
/*
- n: 수빈의 위치
- k: 동생의 위치
*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("E:/vsCode_C++/input.txt", "r", stdin);
    freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    if (n == k) {
        cout << "0\n" << n; // 수빈과 동생의 위치가 일치한 경우
        return 0;
    }

    fill(&minTime[0], &minTime[100004], -1);
    q.push(n);
    minTime[n] = 0;
    postion[n] = n;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto nxt : { cur - 1, cur + 1, cur * 2 }) {
            if (nxt < 0 || nxt > 100000) continue;
            if (minTime[nxt] > -1) continue;

            minTime[nxt] = minTime[cur] + 1;
            postion[nxt] = cur;

            q.push(nxt);
        }
    }

    deque<int> track; // 역추적을 위해 deque 사용
    track.push_back(k);
    while (track.front() != n) {
        track.push_front(postion[track.front()]);
    }

    cout << minTime[k] << '\n';
    for (auto c : track) cout << c << ' ';
    return 0;
}