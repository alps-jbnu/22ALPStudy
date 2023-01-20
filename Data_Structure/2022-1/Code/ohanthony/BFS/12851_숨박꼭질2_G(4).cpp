#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool vis[100005]; // 기존 숨박꼭질 문제와 다르게 '개수'를 알아야 하기 때문에 특정 지점을 방문시 여러 가지 경우를 고려해야 하므로 따로 vis 활용
queue<pair<int, int>> q; // X: 현재 지점, Y: 걸린 시간

int main() {
#ifndef ONLINE_JUDGE
    freopen("E:/vsCode_C++/input.txt", "r", stdin);
    freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool isMin = false; // 동생을 찾는 가장 빠른 시간에 도달한 경우를 판단하는 bool 변수
    int count = 0; // 여러가지 경우를 카운트 하는 변수
    int result = 0; // 최솟값을 저장하는 변수

    int n, k;
    cin >> n >> k; // n: 수빈의 위치, k: 동생의 위치

    q.push({ n, 0 });

    while (!q.empty()) {
        int pos = q.front().X;
        int time = q.front().Y;

        q.pop();
        vis[pos] = true; // 똑같은 지점에 도달하는 경우가 여러개 존재할 수 있기에 pop한 후에 방문 여부 확인

        if (pos == k) {
            if (!isMin) {
                isMin = true;
                result = time + 1; // 동생 지점에 처음 방문할 경우 최솟값 저장
                count++;
            }
            else if (isMin && time + 1 == result) count++; // 처음 방문 이후에 여러 경우를 판단하는 조건
        }

        for (auto nxt : { pos - 1, pos + 1, pos * 2 }) {
            if (nxt < 0 || nxt > 100000) continue; // 점이 범위를 벗어난 경우
            if (vis[nxt]) continue;
            q.push({ nxt, time + 1 });
        }
    }


    cout << result - 1 << '\n' << count;
    return 0;
}