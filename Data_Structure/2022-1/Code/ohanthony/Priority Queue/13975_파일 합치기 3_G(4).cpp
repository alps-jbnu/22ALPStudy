#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T, K, page;
/*
- T: 테스트 개수
- K: 소설 구성하는 장의 수
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        priority_queue<ll, vector<ll>, greater<ll>> pq; // 최소힙으로 선언
        cin >> K;
        while (K--) {
            cin >> page;
            pq.push(page);
        }

        ll result = 0;
        while (pq.size() > 1) {
            ll a = pq.top();
            pq.pop();

            ll b = pq.top();
            pq.pop();

            ll temp = a + b;
            result += temp;
            pq.push(temp);
        }
        cout << result << "\n";
    }
    return 0;
}