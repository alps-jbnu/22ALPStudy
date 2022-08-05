#include<bits/stdc++.h>
using namespace std;

pair<int, int> tree[10002];
int height[10002];
vector<int> depth[10002];
int hei = 1;
int node[10002] = { 0 };
void left(int a) {
	
	if(tree[a].first!=-1)	left(tree[a].first);
	height[a] = hei++;
	if (tree[a].second != -1)	left(tree[a].second);
}

void dfs(int a,int h) {
	depth[h].push_back(a);
	if (tree[a].first != -1)	dfs(tree[a].first, h + 1);
	if (tree[a].second != -1)	dfs(tree[a].second, h + 1);
}

int main() {
	int n;
	cin >> n;
	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		cin >> tree[num].first >> tree[num].second;
		node[tree[num].first] = node[tree[num].second] = 1;
	}
	int root=0;
	for (int i = 1; i <= n; i++) {
		if (node[i]==0) {
			root = i;
		}
	}

	left(root);
	dfs(root,1);
	int mx = 0;
	int d = 0;
	for (int i = 1; depth[i].size()!=0; i++) {
		for (int j = 0; j < depth[i].size(); j++) {
			for (int k = j; k < depth[i].size(); k++) {
				if (mx < height[depth[i][k]] - height[depth[i][j]]+1) {
					mx = height[depth[i][k]] - height[depth[i][j]] + 1;
					d = i;
				}
			}
		}
	}
	cout << d << " " << mx;

}