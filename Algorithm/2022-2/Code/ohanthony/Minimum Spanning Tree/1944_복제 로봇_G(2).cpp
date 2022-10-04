#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int n, m, result;
int keyCount;
/*
- n: 미로의 크기
- m: 열쇠의 개수
*/

string info[55];
int keyNum[55][55];
int Parent[255];
bool flag = true;

pair<int, int> st;
vector<pair<int, int>> key;
vector<pair<int, pair<int, int>>> edge;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// bfs를 통해 간선의 가중치를 구함
void bfs(int st_x, int st_y, int ex, int ey, int node1, int node2){
	bool vis[55][55] = { 0, };
	queue<pair<pair<int, int>, int>> q;
	q.push({{st_x, st_y}, 0});
	vis[st_x][st_y] = true;

		while(!q.empty()){
			int a = q.front().X.X;
			int b = q.front().X.Y;
			int cnt = q.front().Y;
			q.pop();

			if(a == ex && b == ey){ 
				edge.push_back({cnt, {node1, node2}});
				return;
			}

			for(int dir = 0; dir < 4; dir++){
				int nx = a + dx[dir];
				int ny = b + dy[dir];

				if(nx >= 0 && ny >= 0 && nx < n && ny < n){
					if(info[nx][ny] == '1') continue;
					if(vis[nx][ny]) continue;

					vis[nx][ny] = true;
					q.push({{nx, ny}, cnt + 1});
				}
			}
		}	
		flag = false;
}

int Find_Parent(int a){
	if(a == Parent[a]) return a;
	else return Parent[a] = Find_Parent(Parent[a]);
}

bool SameParent(int a, int b){
	a = Find_Parent(a);
	b = Find_Parent(b);

	if(a == b) return true;
	return false;
}

void Union(int a, int b){
	a = Find_Parent(a);
	b = Find_Parent(b);

	Parent[b] = a;
}

void Kru(){
	for(int i = 0; i < keyCount; i++) Parent[i] = i;
	sort(edge.begin(), edge.end());

	for(int i = 0; i < edge.size(); i++){
		int cost = edge[i].X;
		int node1 = edge[i].Y.X;
		int node2 = edge[i].Y.Y;

		if(!SameParent(node1, node2)){
			Union(node1, node2);
			result += cost;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	keyCount = 1;
	for(int i = 0; i < n; i++) cin >> info[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(info[i][j] == 'S'){
				st.X = i;
				st.Y = j;
			}
			else if(info[i][j] == 'K'){
				key.push_back({i, j});
				keyNum[i][j] = keyCount++;
			}
		}
	}

	for(int i = 0; i < key.size(); i++){
		int x = key[i].X;
		int y = key[i].Y;
		bfs(st.X, st.Y, x, y, 0, keyNum[x][y]);

		if(!flag){
			cout << -1;
			return 0;
		}
	}

	for(int i = 0; i < key.size(); i++){
		int x = key[i].X;
		int y = key[i].Y;

		for(int j = i + 1; j < key.size(); j++){
			int xx = key[j].X;
			int yy = key[j].Y;

			bfs(x, y, xx, yy, keyNum[x][y], keyNum[xx][yy]);
			if(!flag){
				cout << -1;
				return 0;
			}
		}
	}

	if(!flag) return 0;

	Kru();
	cout << result;
	return 0;
}
 