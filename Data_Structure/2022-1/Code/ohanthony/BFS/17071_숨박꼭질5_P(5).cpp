#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;
bool vis[500005][2]; // odd or even의 초에 따라 값이 달라지기 때문에 2차원 bool 사용 
int n, k;
/*
- n: 수빈의 위치
- k: 동생의 위치
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    vis[n][0] = true;
    q.push({ n, 0 });

    while (!q.empty()) {
        int pos = q.front().X;
        int time = q.front().Y;
        int boost = k + time * (time + 1) / 2;
        q.pop();

        if (boost > 500000) {
            cout << "-1";
            return 0;
        }

        if (pos == boost || vis[boost][time % 2]) {
            cout << time;
            return 0;
        }

        for (auto nxt : { pos - 1, pos + 1, pos * 2 }) {
            if (nxt >= 0 && nxt <= 500000 && !vis[nxt][(time + 1) % 2]) {
                q.push({ nxt, time + 1 });
                vis[nxt][(time + 1) % 2] = true;
            }
        }
    }

    return 0;
}