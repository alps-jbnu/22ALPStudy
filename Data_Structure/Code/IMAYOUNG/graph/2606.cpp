#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool chk[101];
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    vector<int> v[101];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    int cnt = 0;
    chk[1] = true;
    // 감염된 컴퓨터 찾기
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cnt += 1;
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (!chk[next]) {
                chk[next] = true;
                q.push(next);
            }
        }
    }
    cnt -= 1; // 시작점 제외
    printf("%d", cnt);
    return 0;
}


출처: https://intaehwang.tistory.com/19 [황인태 블로그]