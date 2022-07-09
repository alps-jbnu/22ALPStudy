#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;

bool Visited[MAX] = { 0, };
int N, K;
 
void BFS(int n, int k)
{
	int count = 0;
    queue<int> q;
    
    q.push(n);
 
    while(!q.empty())
    {
        int p = q.size();
 
        for(int i = 0; i < p; i++)
        {
            n = q.front();
            q.pop();
            
            if(n == k)
            {
                cout << count;
                return;
            }
                
            if(n > 0 && Visited[n - 1] == 0)
            {
                q.push(n - 1);
                Visited[n - 1] = 1;
            }
            
            if(n < MAX && Visited[n+1] == 0)
            {
                q.push(n + 1);
                Visited[n + 1] = 1;
            }
            
            if(n * 2 <= MAX && Visited[n * 2] == 0)
            {
                q.push(n * 2);    
                Visited[n * 2] = 1;
            }
        }
        count++;
    }
}
 
int main() 
{
    cin >> N >> K;
    
    BFS(N, K);
    
    return 0;
}