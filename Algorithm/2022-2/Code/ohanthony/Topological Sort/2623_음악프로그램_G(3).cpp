#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int N, M, num;
/*
- N: 가수의 수
- M: 보조 PD의 수
- num: 보조 PD가 담당한 가수의 수
*/

vector<int> result; // 남일이가 가수 출연 순서를 정할 수 있는지 판별하는 vector
vector<int> singer[1005];
int deg[1005];

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N >> M;
	while(M--){
		cin >> num;
		int order[1005] = {0,  };
		for(int i = 1; i <= num; i++){
			cin >> order[i];
			if(i > 1){ 
				singer[order[i-1]].push_back(order[i]);
				deg[order[i]]++;
			}
		}
	}

	queue<int> q;
	for(int i = 1; i <= N; i++){
		if(deg[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int cur = q.front(); q.pop();
		result.push_back(cur);

		for(auto nxt : singer[cur]){
			deg[nxt]--;
			if(deg[nxt] == 0) q.push(nxt);
		}
	}

	if(result.size() != N) cout << 0; // 출연 가수 수와 result 크기가 다른 경우 순서를 정하는 것이 불가능
	else for(auto c : result) cout << c << '\n';
	return 0;
}
