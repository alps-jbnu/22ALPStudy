#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int V, E;
/*
- V: 정점의 개수
- E: 간선의 개수
- A, B: 정점 정보
- C: A->B 가중치
*/
tuple<int, int, int> edge[100005];

vector<int> p(10005, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool isDifGroup(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0; // 같은 그룹
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int A, B, C;
        cin >> A >> B >> C;
        edge[i] = {C, A, B};
    }

    // 가중치 값을 오름차순으로 정렬
    sort(edge, edge + E);

    int count = 0; // 주어진 정점을 다 돌았는지 확인 여부를 판단하는 변수
    int result = 0;
    for(int i = 0; i < E; i++){
        int A, B, C;
        tie(C, A, B) = edge[i];
        if(!isDifGroup(A, B)) continue;

        result += C;
        if(++count == V-1) break;
    }

    cout << result;
    return 0;
}