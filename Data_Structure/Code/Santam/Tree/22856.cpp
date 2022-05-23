#include <iostream>

using namespace std;

int node_n,sum = 0,vis_node=0;
bool res = false;
bool vis[100001] = { false };
int lc[100001] = { 0 };
int rc[100001] = { 0 };

int Search(int n)
{
	if (n == -1) return -1;	
	sum++;
	if (Search(lc[n]) != -1) sum++;
	vis_node++;
	if (Search(rc[n]) != -1) sum++;	
	
	if (vis_node == node_n&&!res)
	{
		cout << sum - 1; res = true;
	}
	return 0;
}

int main()
{
	cin >> node_n;
	for (int i = 0;i < node_n;i++)
	{
		int node;
		cin >> node; 
		cin >> lc[node] >> rc[node];
	}
	Search(1);
	return 0;
}
/*
중위 순위 문제인데, 중위 순위에서 몇가지를 변형할 필요가 있어서 변형했다.
1. 유사 중위 순위라서 부모노드를 찍고 좌측 노드로 간 후에, 다시 부모 노드, 우측 노드로 이동하는 순서라는 게 한사이클
2. 마지막 방문 노드를 찍고 나서 더이상 유사 중위 순위를 못하면 종료하는 조건에서 단순히 마지막 노드를 찍었다고 바로 출력이 되면 안된다.
3. 마지막 방문 노드를 찍을 때, 그 노드가 죄측 노드였다면 다시 부모노드를 찍고 부모의 우측 노드가 없다는 게 확인되고 종료된다.
4. 즉, 좌측 자식노드를 간 이후에 현재의 노드를 방문했다고 해야 현재 노드가 방문이 된 것
5. 위의 방식을 적용 한 후에는, 우측노드까지 방문한 이유 방문한 결과 sum값에 처음 루트에서 시작할 때 임의로 1이 더해졌기에 sum-1을 넣어줌
6. 5에서 출력할때, 위의 재귀는 마지막 노드가 아닌 루트까지 돌아가기 때문에 출력 즉시 재귀구조가 끝나야 된다.(여기선 일회 출력이후 출력을 안하도록 설정)
*/