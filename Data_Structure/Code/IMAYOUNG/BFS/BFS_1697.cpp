#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[100002];
int n,t;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t;
  fill(dis, dis+100001,-1);
  dist[n] = 0;
  queue<int> q;
  q.push(n);
  while(dis[t] == -1){
    int num = q.front(); q.pop();
    for(int nt : {num-1, num+1, 2*num}){
      if(nt < 0 || nt > 100000) continue;
      if(dist[nt] != -1) continue;
      dis[nt] = dist[num]+1;
      q.push(nt);
    }        
  }
  cout << dis[t];
}