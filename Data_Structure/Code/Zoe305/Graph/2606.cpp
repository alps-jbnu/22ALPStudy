#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[101];
bool vis[101];
int cnt = 0;

void dfs(int cur){
    vis[cur] = true;
    for(int i = 0; i < vec[cur].size(); i++){
        int x = vec[cur][i];
        if(!vis[x]){
            dfs(x);
            cnt++;
        }

    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u ,v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    dfs(1);
    cout << cnt << '\n';

    return 0;
}