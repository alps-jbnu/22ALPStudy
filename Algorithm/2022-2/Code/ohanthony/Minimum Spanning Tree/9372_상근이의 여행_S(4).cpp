#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t; // t: 테스트 케이스 수
	while(t--){
		int n, m;
		cin >> n >> m; // n: 국가의 수, m: 비행기 종류
		while(m--){
			int a, b;
			cin >> a >> b;
		}

		// 문제 조건에서 모든 노드를 방문할 수 있는 경로가 존재한다는 것을 생각하면 되므로 간선이 n-1인 경우가 항상 최소이다.
		cout << n-1 << '\n'; 
	}	
	return 0;
}
 