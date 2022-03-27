#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 200001
using namespace std;

int N, K;
bool Visited[MAX] = { 0, };
queue<pair<int, int>> q; // 우선순위를 고려해줘야 하여 pair로 2개 int 받아옴
 
void BFS()
{
    while(!q.empty())
    {
        int n = q.front().first;
		int cost = q.front().second;
		
		Visited[n] = true;
		q.pop();
		
		if(n == K)
        {
            cout << cost;
            return;
        }
        
        int n3 = n * 2;
        if(n3 >= 0 && n3 <= MAX && Visited[n3] == 0)
        {
        	q.push({ n3, cost });
        	Visited[n] = true;
        }
        
        int n1 = n - 1;
        if(n1 >= 0 && n1 <= MAX && Visited[n1] == 0)
        {
        	q.push({ n1, cost + 1 });
        	Visited[n] = true;
        }
        
        int n2 = n + 1;
        if(n2 >= 0 && n2 <= MAX && Visited[n2] == 0)
        {
        	q.push({ n2, cost + 1 });
        	Visited[n] = true;
        }
    }
}
 
int main() 
{
	cin >> N >> K;
    
    q.push({ N, 0 });
    BFS();
    
    return 0;
}