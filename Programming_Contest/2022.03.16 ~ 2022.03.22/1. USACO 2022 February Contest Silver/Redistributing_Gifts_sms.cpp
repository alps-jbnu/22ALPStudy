#include <bits/stdc++.h>

using namespace std;

void dfs(int pos, int curr, vector<vector<bool>>& check, vector<vector<int>>& v)
{
    if(check[pos][curr]) return;
    check[pos][curr] = true;
    for(int &next : v[curr])
    {
        dfs(pos, next, check, v);
    }
}


int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n+1, vector<int>(n, 0));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> v[i][j];
        }
        while(v[i].back() != i) v[i].pop_back();
    }
    vector<vector<bool>> check(n+1, vector<bool>(n+1, false));
    for(int i=1;i<=n;i++) dfs(i, i, check, v);
    for(int i=1;i<=n;i++)
    {
        for(int &gift : v[i])
        {
            if(check[gift][i] && check[i][gift])
            {
                cout << gift << "\n";
                break;
            }
        }
    }
    return 0;
}
