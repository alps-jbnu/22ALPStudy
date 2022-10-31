#include <iostream>
#include <vector>
#include <algorithm>
//14621 - 나만 안되는 연애 

using namespace std;
int N, M;    //N=학교의 수(노드) M=도로의 수(간선)
int parent[1001];
char gender[1001];
int ans = 0;
bool flag[1001];
vector<pair<int, pair<int, int>>> edges;

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {    //부모테이블 상에서 부모를 자기자신으로 초기화 및 성별정보 입력
        char s; cin >> s;
        parent[i] = i;
        gender[i] = s;
    }

    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d;
        edges.push_back({ d,{u,v} });    //거리를 기준으로 정렬하기 위해 거리를 튜플의 첫번째 원소로 입력
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if (gender[a] == gender[b]) continue;    //성별이 같으면 무시
        if (findParent(a) != findParent(b)) {
            ans += cost;
            unionParent(a, b);
            flag[a] = flag[b] = true;    //해당 노드를 방문했으니 TRUE처리
        }
    }
    for (int i = 1; i <= N; i++) {    //한번이라도 방문 하지 않은 노드가 있다면 연결x 
        if (!flag[i]) {
            cout << -1;
            return 0;
        }
    }

    cout << ans;
    return 0;
}

//MST의 조건 : 모든 정점들이 연결되어야 하며 사이클을 포함하지 않고 간선의 가중치의 합이 최소 