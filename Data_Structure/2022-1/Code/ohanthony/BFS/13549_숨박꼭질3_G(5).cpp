#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

deque<int> d; // 기존의 숨바꼭질에서의 우선순위가 동일했던거와는 다르게 순간이동 하는 경우는 우선순위가 높은걸 고려해 deque를 활용
int result[100005];
int n, k;
/*
- n: 수빈 위치
- k: 동생 위치
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    fill(&result[0], &result[100004], -1);
    d.push_back(n);
    result[n] = 0;

    while (!d.empty()) {
        auto cur = d.front();
        d.pop_front();

        if (cur * 2 < 100005 && result[cur * 2] == -1) {
            result[cur * 2] = result[cur];
            d.push_front(cur * 2);
        }

        for (auto nxt : { cur - 1, cur + 1 }) {
            if (nxt < 0 || nxt > 100005) continue;
            if (result[nxt] > -1) continue;

            result[nxt] = result[cur] + 1;
            d.push_back(nxt);
        }
    }

    cout << result[k];

    return 0;
}