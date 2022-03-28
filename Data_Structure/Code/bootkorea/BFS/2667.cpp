#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
 
int N, cnt = 0;
int arr[26][26];
int Direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<int> vec;
bool Visited[26][26];

void Dfs(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int dx = x + Direction[i][0];
        int dy = y + Direction[i][1];
 
        if(Visited[dx][dy] == false && arr[dx][dy] == 1)
        {
        	Visited[dx][dy] = true;
        	cnt++;
        	Dfs(dx, dy);
        }
    }
}
 
int main(void)
{
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        for(int j=0; j < N;j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }
	
	for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) 
        {
            if(Visited[i][j] == false && arr[i][j] == 1) {
            	Visited[i][j] = true;
                cnt++;
                Dfs(i, j);
                
                vec.push_back(cnt);
                cnt = 0;
            }
        }
    }
	
	sort(vec.begin(), vec.end());
	
    printf("%d\n", vec.size());
    
    for(int i = 0; i < vec.size(); i++)
    {
    	printf("%d\n", vec[i]);
    }
 
    return 0;
}