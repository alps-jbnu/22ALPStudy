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

char MW[1005];                    // 남초 여초 구분 index
vector<pair<int, int>> school[1005]; // {비용, 정점 번호}
bool vis[1005];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   cin >> n >> m;
   for(int i = 1; i <= n; i++) cin >> MW[i];
   while(m--){
      int u, v, d;
      cin >> u >> v >> d;
      school[u].push_back({d, v});
      school[v].push_back({d, u});
   }

   int result = 0; // 앱 경로의 길이
   int cnt = 0;    // 현재 선택된 간선의 수
   
   // {비용, 정점1, 정점2}
   priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;

   vis[1] = 1;
   for(auto nxt : school[1]){
      if(MW[nxt.Y] != MW[1]){ // 연결되는 지점이 남-여 일 경우에만 pq에 push
         pq.push({nxt.X, 1, nxt.Y});
      }
   }
   
   while(!pq.empty()){ // 문제 조건상 cnt == n-1이 안될 수 있으므로 cnt < n-1을 조건식으로 하면 안된다.
      int dist, a, b;
      tie(dist, a, b) = pq.top();
      pq.pop();

      if(vis[b]) continue;

      result += dist;
      vis[b] = 1;
      cnt++;
      for(auto nxt : school[b]){
         if(!vis[nxt.Y] && MW[b] != MW[nxt.Y]){
            pq.push({nxt.X, b, nxt.Y});
         }
      }
   }

   if(cnt < n-1) cout << -1;
   else cout << result;
   return 0;
}
 