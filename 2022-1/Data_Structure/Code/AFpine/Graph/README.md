# **Problem Solving Review**

## [환승](https://www.acmicpc.net/problem/5214)

정점들간의 간선을 효율적으로 구현하는 문제

### **구현**

[N개의 정점과 M개의 하이퍼튜브, 그리고 한 하이퍼튜브는 K개의 역을 연결한다]

어떤 정점(이 문제에선 역) i 에 대하여 만약 m개의 하이퍼튜브에 정점 i 가 속한다면, 그 m개의 하이퍼튜브 안에 들어있는(자신을 포함하고 중복될 수 있는) mK 개의 정점에 이동할 수 있다. 즉, 간선이 존재한다. 이동하는데 드는 비용은 1 이다. 한 하이퍼튜브에 속한 K개의 정점을 입력받았을 때, 그 정점들에 각각 K-1개의 양방향 간선을 만들어 주는 것은 비효율 적이라고 생각했다(M*K^2에 비례한다). 이렇게 전처리 비용을 많이 소모하여 간선을 만들어도 실제 BFS를 실행할 때 그 간선 전체를 탐색하여 이동하는 것은 별로 매력적이지 않다.

그래서 한 하이퍼튜브를 하나의 집합으로 생각하여 K개의 원소가 있는 M개의 하이퍼튜브 집합을 만들었다(hypertube). 또한 각 정점에 자신이 어느 하이퍼튜브에 속해 있는지를 저장하는 배열(hypertubeindex)을 만들었다. 이러면 전체 간선을 만드는 전처리 비용은 M*K(입력의 크기와 같음)에 비례하는 비용이 들기 때문에 이 전의 작업보다 매력적이다. 또한 BFS 안에서도 자신의 정점 안의 hypertubeindex 배열에 저장되어있는 hypertube에 접근하여 전체를 탐색하므로, 이전 방법보다 성능이 느리지 않다.

### **시간 초과(TLE) 및 해결**

위의 방법으로 구현했을 때, 시간 초과가 나와서 접근을 잘못했다고 생각했다. hypertube를 구현할 때, 사전적 의미 그대로 집합이기 때문에 STL set을 사용하여 구현했었다. 그 hypertube를 이중배열을 사용하여 구현했더니 통과되었다. 

[STL std::set은 balanced binary tree로 구현되어있다]

어떤 집합에서 한 값을 찾을 때는, 선형적인 데이터 구조에서 탐색하는 것보다 balanced binary tree에서 탐색하는 것이 더 빠르다. 하지만 이 문제에서 BFS내에서 현재 정점이 자신이 속한 hypertube 집합속의 모든 정점들을 가지고 이동하려 하기 때문에, 특정한 값을 찾는 것이 아니라 전체를 탐색한다. 구조 전체를 탐색할 때, std::set은 std::vector보다 더 느리다 (https://stackoverflow.com/questions/56832563/why-is-iterating-over-a-stdset-so-much-slower-than-over-a-stdvector)

```cpp
#include <bits/stdc++.h>

//5214 (BFS)

using namespace std;

static const int INF = 1000000000;

struct Station
{
    int n;                          //station number(useless)
    vector<int> hypertubeindex;     //hypertube index(number) that contains this station
};

Station station[100001];            
bool visited[100001];
int dist[100001];               

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int N,K,M;
    int num;
    queue<int> q;                   //BFS queue

    cin>>N>>K>>M;

    vector<vector<int>> hypertube(M);
                                    //vector of hypertube set(if use set, TLE)
    
    for(int i = 0;i<M;++i)
    {
        for(int j = 0;j<K;++j)
        {
            cin>>num;                                       //station number
            hypertube[i].push_back(num);                    //in hypertube set [i] contains station 'num'
            station[num].hypertubeindex.push_back(i);       //in num station, you can use hybertube set [i]
        }
    }

    dist[1] = 1;        //start from station 1
    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        int cur = q.front();        //current station number
        q.pop();
        if(cur == N)
        {
            break;
        }
        for(auto x : station[cur].hypertubeindex)
        {//x is index of hypertube set that contains current station
            for(auto h : hypertube[x])
            {//can move other stations of hypertube set [x]
                if(visited[h] == false)
                {
                    visited[h] = true;
                    dist[h] = dist[cur] + 1;
                    q.push(h);
                }
            }
        }
    }

    if(dist[N] != 0)            //or dist[N] != INF (if initialize with INF)
    {
        cout<<dist[N]<<'\n';
    }
    else                        //if you can't approach to station N
    {
        cout<<"-1\n";
    }

    return 0;
}
```