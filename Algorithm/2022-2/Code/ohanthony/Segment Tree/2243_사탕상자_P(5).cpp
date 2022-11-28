#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
#define ll long long
#define X first
#define Y second
const int NUMBER = 1000005;

int n, a, b, c;
/*
- n: 사탕상자에 손을 댄 횟수
- a = 1: 사탕상자에서 사탕을 꺼내는 경우
       b: 꺼낼 사탕의 순위

- a = 2: 사탕을 넣는 경우
       b: 넣을 사탕의 맛
       c: b의 개수
*/

ll arr[NUMBER];
ll tree[NUMBER * 4];

// 상자 안에 index번째 맛있는 사탕 찾는 경우
ll query(int st, int en, int node, int index) {
    if (st == en) return en;

    int mid = (st + en) / 2;

    // index에 해당하는 index 값보다 더 많은 사탕 가지고 있는 경우에 왼쪽 탐색
    if (tree[node * 2] >= index) return query(st, mid, node * 2, index);

    // index-왼쪽자식이 가지고 있는 사탕의 수
    else return query(mid + 1, en, node * 2 + 1, index - tree[node * 2]);
}

ll update(int st, int en, int node, int index, ll dif) {
    if (index < st || index > en) return tree[node];
    if (st == en)  return tree[node] = dif;

    int mid = (st + en) / 2;
    return tree[node] = update(st, mid, node * 2, index, dif) + update(mid + 1, en, node * 2 + 1, index, dif);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 1) {
            cin >> b;

            ll taste = query(1, NUMBER, 1, b);
            cout << taste << '\n';

            // 사탕 한개 꺼낸걸 반영해 update 시킴
            update(1, NUMBER, 1, taste, arr[taste] - 1);
            arr[taste]--;
        }
        else {
            cin >> b >> c;
            update(1, NUMBER, 1, b, arr[b] + c);
            arr[b] += c;
        }
    }
    return 0;
}