#define MAX 100001

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
pair<int, int> points[100001];

int dx[2]{1, -1};
queue<int> Q;
vector<int> ans;

void bfs() {
  while(!Q.empty()) {
    if(points[k].first != -1) break;
    int cur{Q.front()};
    Q.pop();
    for(int i{}; i<2; i++) {
      int nxt{cur+dx[i]};
      if(nxt<0 || nxt>=MAX) continue;
      if(points[nxt].first != -1) continue;
      Q.push(nxt);
      points[nxt].first = points[cur].first + 1;
      points[nxt].second = cur;
    }
    int nxt{cur*2};
    if(nxt<0 || nxt>=MAX) continue;
    if(points[nxt].first != -1) continue;
    Q.push(nxt);
    points[nxt].first = points[cur].first + 1; 
    points[nxt].second = cur;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i{}; i<MAX; i++) {
    points[i]={-1, -1};
  }
  cin>>n>>k;
  Q.push(n);
  points[n] = {0, -1};
  bfs();
  
  int cur{k};
  while(true) {
    if(cur == -1) break;
    ans.push_back(cur);
    cur = points[cur].second;
  }
  cout<<points[k].first<<"\n";
  auto it{ans.end()};
  while(true) {
    it--;
    cout<<*it<<" ";
    if(it == ans.begin()) break;
  }

  return 0;
}