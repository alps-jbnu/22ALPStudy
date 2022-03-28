#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second
int vis[100002];
int n,k;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(vis, vis+100001,-1);
    vis[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(vis[k] == -1){
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1, cur+1, 2*cur}){
            if(nxt < 0 || nxt > 100000) continue;
            if(vis[nxt] != -1) continue;
            vis[nxt] = vis[cur]+1;
            Q.push(nxt);
        }
    }
    cout << vis[k];
    return 0;
}