#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1005];
bool vis[1005];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y;


  cin >> x >> y;  
  while(m--){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);    
  }

  int num = 0;
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    num++;
    queue<int> Q;
    Q.push(i);
    vis[i] = true;
    while(!Q.empty()){
      int cur = Q.front();
      q.pop();
      for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        q.push(nxt);
        vis[nxt] = true;
      }
    }
  }
  cout << num;

  return 0;
}