#include <bits/stdc++.h>

using namespace std;

int student[100001];        //value is next vertex of index
int cycle[100001];          //0 is unknown , 1 is cycle(team), 2 is not cycle(not team)
int visited[100001];

void DFS(int now)
{
    if(cycle[now] == 0 && cycle[student[now]] != 0)
    {//자신의 팀 여부는 모르지만, 자신이 가리키는 정점의 팀 여부가 정해져 있으면(그 정점이 팀이던 아니던) 자신은 팀에 속해있지 않다
        cycle[now] = 2;
        return;
    }
    if(visited[student[now]] == 0)
    {//첫 번째 방문
        visited[student[now]] = 1;
        DFS(student[now]);
    }
    else if(visited[student[now]] == 1)
    {//두 번째 방문하는 정점들은 팀에 속해있다
        visited[student[now]] = 2;
        if(cycle[student[now]] == 0)
        {//두 번째 방문하는 사이클에서 자신이 가리키는 정점은 팀에 속해있다(자신도 포함해서)
            cycle[student[now]] = 1;
        }
        DFS(student[now]);
    }
    if(cycle[now] == 0)
    {//DFS를 종료하는데 자신의 팀 여부가 정해지지 않았다면, 이 DFS에는 사이클(팀)이 존재하지 않거나, 그 팀에 자신이 속하지 못한 것
        cycle[now] = 2;         //그러므로 자신은 팀에 속하지 못했다
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int TC;
    cin>>TC;
    
    for(int t = 0;t<TC;++t)
    {
        int cnt = 0;
        int n;
        cin>>n;

        for(int i = 1;i<=n;++i)
        {
            cin>>student[i];
            visited[i] = 0;
            cycle[i] = 0;
            if(student[i] == i)
            {
                cycle[i] = 1;
            }
        }

        for(int i = 1;i<=n;++i)
        {
            if(cycle[i] != 0)
            {
                continue;
            }
            visited[i] = 1;
            DFS(i);
        }

        for(int i = 1;i<=n;++i)
        {
            if(cycle[i] != 1)
            {
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}