#include <bits/stdc++.h>

//11967 Turning light on

using namespace std;

struct Room
{//ROOM
    bool light = false;             //true : this room is light on
    bool visit = false;             //true : this room is visited least one time
    vector<pair<int,int>> switchv;  //switches in this room
};

Room hut[101][101];
bool visited[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lightcnt=1;
    int N,M;
    int x,y,a,b;
    set<pair<int,int>>lightroomset;     //in this set, there are rooms that light is on and not visited
    bool change = true;                 //flag that turn switch on in this iteration 

    cin>>N>>M;

    for(int i = 1;i<=M;++i)
    {
        cin>>x>>y>>a>>b;
        
        hut[x][y].switchv.push_back({a,b});
    }

    lightroomset.insert({1,1});
    hut[1][1].light = true;

    while(!lightroomset.empty() && change == true)      //visited all light on room or can't visited new light room
    {
        queue<pair<int,int>>Q;

        for(int i = 1;i<=N;++i)
        {
            for(int j = 1;j<=N;++j)
            {
                visited[i][j] = false;
            }
        }

        change = false;
        visited[1][1] = true;
        Q.push({1,1});

        while(!Q.empty())
        {
            pair<int,int> cur = Q.front();
            Q.pop();

            if(lightroomset.find(cur) != lightroomset.end())
            {//if visited new light room, erase in set
                lightroomset.erase(lightroomset.find(cur));
            }
            
            if(hut[cur.first][cur.second].visit == false)
            {//turn the switches on in this room
                hut[cur.first][cur.second].visit = true;
                for(auto e : hut[cur.first][cur.second].switchv)
                {
                    if(hut[e.first][e.second].light == false)
                    {
                        change = true;
                        lightroomset.insert({e.first,e.second});
                        hut[e.first][e.second].light = true;
                        lightcnt++;
                        //count of turn on the switch
                    }
                }
            }

            for(int dir = 0;dir<4;++dir)
            {
                int x = cur.first + dx[dir];
                int y = cur.second + dy[dir];

                if(x < 1 || x > N || y < 1 || y > N)
                {
                    continue;
                }
                if(hut[x][y].light == true && visited[x][y] == false)
                {
                    visited[x][y] = true;
                    Q.push({x,y});
                }
            }
        }

    }

    cout<<lightcnt<<"\n";
    
    
    return 0;
}