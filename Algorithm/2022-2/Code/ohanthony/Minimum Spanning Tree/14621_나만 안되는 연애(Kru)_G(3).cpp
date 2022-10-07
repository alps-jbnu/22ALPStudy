#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int n, m;
/*
- n: 학교의 수 
- m: 학교 연결하는 도로 개수
*/

char MW[1005]; 						 // 남초 여초 구분 index
tuple<int, int, int> school[10005];   // {비용, 정점1, 정점2}

vector<int> p(1005, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_dif_group(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return 0; // 같은 그룹인 경우 고려 x
    if(p[u] == p[v]) p[u]--;

    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;

    return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> MW[i];
	for(int i = 0; i < m; i++){
		int u, v, d;
		cin >> u >> v >> d;
		school[i] = {d, u, v};
	}

	sort(school, school+m);

    int result = 0; // 앱 경로의 길이
	int cnt = 0; 	// 현재 선택된 간선의 수

	for(int i = 0; i < m; i++){
        int dist, a, b;
        tie(dist, a, b) = school[i];

        if(MW[a] == MW[b]) continue; // 남녀 구분
        if(!is_dif_group(a, b)) continue;
        result += dist;
        cnt++;
    }

    if(cnt < n-1) cout << -1;
    else cout << result;
	return 0;
}
 