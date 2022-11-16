#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int N, M, A, B;
/*
- N: 문제의 수
- M: 먼저 푸는 것이 좋은 문제에 대한 정보 개수
- A, B: A->B 순서로 문제를 풀어야 한다
*/

vector<int> problem[32005];
int deg[32005];

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> N >> M;
    while(M--){
        cin >> A >> B;
        problem[A].push_back(B);
        deg[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq; // 올림차순으로 정렬
    for(int i = 1; i <= N; i++){
        if(deg[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top(); // 우선순위 큐를 이용함으로써 조건 2, 3 한번에 만족시킬 수 있다.
        pq.pop();

        cout << cur << ' ';
        for(auto nxt : problem[cur]){
            if(--deg[nxt] == 0){
                pq.push(nxt);
            }
        }
    }
    return 0;
}