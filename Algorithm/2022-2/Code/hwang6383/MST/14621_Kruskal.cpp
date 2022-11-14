#include <bits/stdc++.h>

using namespace std;

int male = 0;
int female = 0;
vector<int> p(1001, -1);
vector<int> s(1001, -1);
int find_parent(int x)
{
    if(p[x] < 0) return  x;
    return p[x] = find_parent(p[x]);
}
bool is_diff_group(int a, int b)
{
    a = find_parent(a); b = find_parent(b);
    if(a == b) return false;
    if(a > b) p[a] = b;
    else p[b] = a;
    return true;
}

int N,M;
tuple<int,int,int> tp[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        char sex; cin >> sex;
        if(sex == 'M')
        {
            if(!male)
                male = i;
            s[i] = male;
        }
        else
        {
            if(!female)
                female = i;
            s[i] = female;
        }
    }
    for(int i = 0; i < M; i++)
    {
        int u,v,d; cin >> u >> v >> d;
        tp[i] = make_tuple(d,u,v);
    }
    sort(tp,tp+M);
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < M; i++)
    {
        int a,b,c;
        tie(c,a,b) = tp[i];
        if(s[a] == s[b]) continue;
        if(!is_diff_group(a,b)) continue;
        ans += c;
        cnt++;
        if(cnt == N - 1) break;
    }
    if(cnt == N - 1)
        cout << ans;
    else
        cout << -1;
    return 0;
}
