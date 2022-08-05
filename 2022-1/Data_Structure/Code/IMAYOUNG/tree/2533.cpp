#include <bits/stdc++.h>
using namespace std;

//dp 개념 알아보기..

int n,parent;
vector<int> e[1000001];
int dp[1000001][2]; //0이 어답터, 1이 일반인
bool visited[1000001];

void find(int x){
    visited[x]=true;
    dp[x][0]=1;
    for(int i=0; i<e[x].size(); i++){
        int child = e[x][i];
        if(visited[child]) continue;
        find(child);
        dp[x][1]+=dp[child][0];
        dp[x][0]+=min(dp[child][1],dp[child][0]);
    }

}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int u,v;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    find(1);
    cout<<min(dp[1][0],dp[1][1]);
}