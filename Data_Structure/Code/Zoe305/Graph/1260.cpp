#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,st;
vector<int> vec[1001];
bool vis[1001];

void dfs(int cur){
  vis[cur] = true;
  cout << cur << ' ';
  for(auto nxt : vec[cur]){
    if(vis[nxt]) continue;    
    dfs(nxt);
  }
}

void bfs(){
  queue<int> Q;
  Q.push(st);
  vis[st] = true;
  while(!Q.empty()){
    int cur = Q.front();
    cout << cur << ' ';
    Q.pop();
    for(auto nxt : vec[cur]){
      if(vis[nxt]) continue;
      Q.push(nxt);
      vis[nxt] = true;
    }    
  }
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> st;

  while(m--){
    int u, v;
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  for(int i = 1; i <= n; i++)
    sort(vec[i].begin(), vec[i].end());
  dfs(st);
  cout << '\n';
  fill(vis+1, vis+n+1, false);
  bfs();

  return 0;
}