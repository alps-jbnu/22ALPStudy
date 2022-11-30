#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
 
using namespace std;
const int INF = 1000000007;
const int MAX_V = 2001;
vector<pair<int, int> > V[2001];
vector<int> find_this;
 
int N, M, T;
int S, G, H;
 
vector<int> dijkstra(const int& start) {
    //각 노드로 이동하는데 필요한 시간을 저장, 처음에는 INF로 초기화
    vector<int> dist(N + 1, INF);
    //시작지점은 0으로 설정
    dist[start] = 0;
 
    priority_queue<pair<int, int> > pq;
    pq.push({ 0, start });
 
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        //만일 이번 코스트가 최단경로가 아니라면 패스
        if (cost > dist[here]) continue;
        for (int i = 0; i < V[here].size(); i++) {
            int there = V[here][i].first;
            int next_cost = cost + V[here][i].second;
            //다음 지점에 대해 최단경로가 갱신되는 경우
            if (next_cost < dist[there]) {
                dist[there] = next_cost;
                pq.push({ -next_cost, there });
            }
        }
    }
 
    return dist;
}
 
int main() {
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        cin >> N >> M >> T;
        cin >> S >> G >> H;
 
        //활용되는 범위에 대해 미리 초기화를 해준다.
        for (int j = 1; j <= N; j++)
            V[j].clear();
        int a, b, c;
        for (int j = 0; j < M; j++) {
            cin >> a >> b >> c;
            V[a].push_back({ b,c });
            V[b].push_back({ a,c });
        }
 
        int temp;
        //항상 초기화를 해준다.
        find_this.clear();
        for (int j = 0; j < T; j++) {
            cin >> temp;
            find_this.push_back(temp);
        }
        //미리 오름차순으로 정렬한다.
        sort(find_this.begin(), find_this.end());
 
        vector<int> root = dijkstra(S);
        vector<int> branch1 = dijkstra(G);
        vector<int> branch2 = dijkstra(H);
 
        vector<int> ret;
        for (int j = 1; j <= N; j++) {
            //시작지점에서 j번 도시까지 걸린 cost가
            //H, G점을 경유해서 돌아간 cost와 동일한 경우
            //ret에 담아 저장해준다.
            if (root[j] == root[G] + branch1[H] + branch2[j] || root[j] == root[H] + branch2[G] + branch1[j]) {
                ret.push_back(j);
            }
        }
 
        //우리가 찾기 위해 등록한 노드가 최단 노드(ret에 담겨있는 노드)중 하나인 경우
        for (int j = 0; j < find_this.size(); j++) {
            int here = find_this[j];
            for (int k = 0; k < ret.size(); k++) {
                if (here == ret[k])
                    cout << here << " ";
            }
        }
        cout << endl;
    }
 
    return 0;
}
