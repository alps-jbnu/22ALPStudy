#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visit[1005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;

  cin >> n >> m;  
  while(m--){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);    
  }

  int num = 0;
  for(int i = 1; i <= n; i++){
    if(visit[i]) continue;
    num++;
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      for(auto nt : adj[cur]){
        if(visit[nt]) continue;
        q.push(nt);
        visit[nt] = true;
      }
    }
  }
  cout << num;
}