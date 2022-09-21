#include<bits/stdc++.h>
using namespace std;

int N, M, r;
/*
- N: 사람의 수
- M: 파티의 수
- r: 진실을 아는 사람의 수
*/

vector<int> know; // 진실을 아는 사람을 know vector에 push_back 해준다
int parents[55]; // 같은 파티에 오는 사람들끼리는 모두 parent가 동일하게 만들어줌
vector<vector<int>> party(50); // party 참여 명단

int Find(int x) {
	if (parents[x] == x) return x;
	return x = Find(parents[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	parents[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> r;

	while (r--) { // 진실을 아는 사람 입력
		int k;
		cin >> k;
		know.push_back(k);
	}

	// parent 초기화
	for (int i = 1; i <= N; i++) parents[i] = i; 

	for (int i = 0; i < M; i++) { // party 명단 입력
		int m, num, prev;
		cin >> m; // 각 파티에서 참석한 사람의 수

		for (int j = 0; j < m; j++) {
			if (j >= 1) { // 같은 파티에 참여한 사람들을 같은 집합으로 합침
				prev = num;
				cin >> num;
				Union(prev, num);
			}
			else cin >> num;

			party[i].push_back(num);
		}
	}


	for (auto& list : party) { // 파티 순회
		bool flag = false;
		for (auto& person : list) { // 파티 참여자 순회
			if (flag) break;

			for (auto& z : know) { // 진실을 아는 사람 순회

				// 파티 참여자 중 진실아는 사람이 있으면 파티에서 거짓말 못함. 즉 flag를 true로
				if (Find(person) == Find(z)) {
					flag = true;
					break;
				}
			}
		}
		if (flag) M--; // 파티에서 거짓말을 할 수 없다면
	}

	cout << M;
	return 0;
}

/*
- Union Find 알고리즘 활용
*/