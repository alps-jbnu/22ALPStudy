#include <bits/stdc++.h>

using namespace std;

vector<int> p(10001,-1);
int find_parent(int x)
{
    if(p[x] < 0) return x;
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

int N, M, t;
tuple<int,int,int> tp[30001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> t;
    for(int i = 0; i < M; i++)
    {
        int A,B,C; cin >> A >> B >> C;
        tp[i] = make_tuple(C,A,B);
    }
    sort(tp,tp+M);
    int cnt = 0;
    long long ans = 0;
    int k = 0;
    for(int i = 0; i < M; i++)
    {
        int a,b,c; tie(c,a,b) = tp[i];
        if(!is_diff_group(a,b)) continue;
        cnt++;
        ans += c;
        ans += t * k++;
        if(cnt == N - 1) break;
    }
    cout << ans;
    return 0;
}
