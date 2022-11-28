#define INF 100000001
#define MX_N 2001

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class info {
    public:
    int to;
    int dis;
    bool vis[101];
    info() {
        to = 0;
        dis = 0;
        for(int i{}; i<101; i++) vis[i] = 0;
    }
    info(int to, int dis) {
        this->to = to;
        this->dis = dis;
        for(int i{}; i<101; i++) vis[i] = 0;
    }
    info(int to, int dis, bool vis[]) {
        info(to, dis);
        for(int i{}; i<101; i++) this->vis[i] = vis[i];
    }
};

class cmp {
    public:
    bool operator()(info &a, info &b)
    {
        return a.dis > b.dis;
    }
};

int T;
int n, m, t; // 교차로, 도로, 목적지 후보의 개수
int s, g, h; // 예술가들의 출발지, 반드시 지나간 교차로 두 개
int a, b, d; // a와 b 사이에 길이 d의 양방향 도로가 있다
int x; // 목적지 후보

bool mustVisit[101];
vector<info> adj[MX_N];
priority_queue<info, vector<info>, cmp> PQ;
info ans[MX_N];

void show() {
    for(int i{}; i<n; i++) {
        ans[i].dis<<' ';
    }
}

void init() {
    for(int i{}; i<MX_N; i++) {
        ans[i].to = 0;
        ans[i].dis = 0;
        for(int j{}; j<101; j++) {ans[i].vis[j] = 0;}
    }
    ans[s].dis = 0;
    ans[s].vis[s] = true;
}

void dijkstra() {
    init();

    info st = ans[s];
    st.to = s;
    PQ.push(st);
    while(!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        if(cur.dis > ans[cur.to].dis) continue;
        for(int i{}; i<adj[cur.to].size(); i++) {
            auto nxt{adj[cur.to][i]};
            if(ans[nxt.to].dis > cur.dis + nxt.dis) {
                ans[nxt.to].dis = cur.dis + nxt.dis;
                nxt.vis[nxt.to] = true;
                PQ.push(info(nxt.to, ans[nxt.to].dis, nxt.vis));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>t;
    cin>>s>>g>>h;
    for(int i{}; i<m; i++) {
        cin>>a>>b>>d;
        adj[a].push_back(info(b,d));
        adj[b].push_back(info(a,d));
    }
    for(int i{}; i<t; i++) {
        cin>>x;
        mustVisit[x] = true;
    }

    dijkstra();
    show();

    return 0;
}