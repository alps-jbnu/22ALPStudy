#include <iostream>
#include <vector>
#include <algorithm>

//14950 - 정복자 
using namespace std;

int N, M, t; //N=도시의 개수(노드), M=도로의 개수(간선), t=정복할때마다 드는 누적비용
vector<pair<int, pair<int, int>>>edges;
int parent[10001];
int ans = 0, cnt = 0;;

int findParent(int x) {
    if (x == parent[x]) return x;
    else return x = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> t;

    for (int i = 1; i <= N; i++) {    //부모 테이블에서, 부모자신을 자기자신으로 초기화
        parent[i] = i;            
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ c,{a,b} });    //비용을 기준으로 정렬하기 위해 튜플의 첫번째 원소에 비용 삽입    
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            ans += cost+cnt*t;
            cnt++;
        }
    }
    cout << ans;
}