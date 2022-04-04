#include <bits/stdc++.h>

//2617 (Exhaustive search)

using namespace std;

static const int INF = 100000000;

struct Bead
{
    int lighter = 0;
    int heavier = 0;
    vector<int> lightV;
    vector<int> heavyV;
};

Bead bead[100];
bool visited[100];
// bool lightdfsstart[100];
// bool heavydfsstart[100];


// void heavyDFS(int cur, int heavier)
// {
//     bead[cur].heavier += heavier;
//     for(auto h : bead[cur].heavyV)
//     {
//         if(visited[h] == false)
//         {
//             visited[h] = true;
//             heavyDFS(h,bead[cur].heavier+1);
//         }
//     }
// }

// void lightDFS(int cur, int lighter)
// {
//     bead[cur].lighter += lighter;
//     for(auto l : bead[cur].lightV)
//     {
//         if(visited[l] == false)
//         {
//             visited[l] = true;
//             lightDFS(l,bead[cur].lighter+1);
//         }
//     }
// }

int searchlightDFS(int cur)
{
    int templighter = 1;
    for(auto l : bead[cur].lightV)
    {
        if(visited[l] == false)
        {
            visited[l] = true;
            templighter += searchlightDFS(l);
        }
    }
    return templighter;
}

int searchheavyDFS(int cur)
{
    int tempheavier = 1;
    for(auto h : bead[cur].heavyV)
    {
        if(visited[h] == false)
        {
            visited[h] = true;
            tempheavier += searchheavyDFS(h);
        }
    }
    return tempheavier;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int a,b;
    int average;
    int result = 0;

    queue<int> Q;

    cin>>N>>M;
    average = (N+1)/2;

    // for(int i = 1;i<=N;++i)
    // {
    //     lightdfsstart[i] = true;
    //     heavydfsstart[i] = true;
    // }

    for(int i = 0;i<M;++i)
    {
        cin>>a>>b;
        //a is heavier than b
        bead[b].heavyV.push_back(a);
        // heavydfsstart[a] = false;
        bead[a].lightV.push_back(b);
        // lightdfsstart[b] = false;
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            visited[j] = false;
        }
        visited[i] = true;
        bead[i].lighter = searchlightDFS(i) - 1;
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            visited[j] = false;
        }
        visited[i] = true;
        bead[i].heavier = searchheavyDFS(i) - 1;
    }

    // for(int i = 1;i<=N;++i)
    // {
    //     if(heavydfsstart[i] == true)
    //     {
    //         Q.push(i);
    //     }
    // }

    // while(!Q.empty())
    // {
    //     int cur = Q.front();
    //     Q.pop();
    //     for(int i = 1;i<=N;++i)
    //     {
    //         visited[i] = false;
    //     }
    //     heavyDFS(cur,bead[cur].heavier);
    // }

    // for(int i = 1;i<=N;++i)
    // {
    //     if(lightdfsstart[i] == true)
    //     {
    //         Q.push(i);
    //     }
    // }

    // while(!Q.empty())
    // {
    //     int cur = Q.front();
    //     Q.pop();
    //     for(int i = 1;i<=N;++i)
    //     {
    //         visited[i] = false;
    //     }
    //     lightDFS(cur,bead[cur].lighter);
    // }

    for(int i = 1;i<=N;++i)
    {
        if(bead[i].lighter >= average || bead[i].heavier >= average)
        {
            result++;
        }
    }

    cout<<result<<"\n";
    return 0;
}