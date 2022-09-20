#include <bits/stdc++.h>
using namespace std;

int N, M, card;
/*
- N: 상근이 가지고 있는 숫자 카드의 개수
- M: 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 수
*/

map<int, bool> m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--) {
        cin >> card;
        m[card] = true;
    }

    cin >> M;
    while (M--) {
        cin >> card;
        if (m.find(card) != m.end()) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    return 0;
}