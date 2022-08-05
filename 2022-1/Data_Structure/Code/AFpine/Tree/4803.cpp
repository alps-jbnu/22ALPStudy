#include <bits/stdc++.h>

//4803 트리

using namespace std;

int n,m;
int T;
int p[501];
int isTree[501];
bool selected[501];
int result;
vector<pair<int,int>> edge;

int find(int a)
{
    if(p[a] < 0)
    {
        return a;
    }
    return p[a] = find(p[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
    {
        return;
    }
    p[b] = a;
}

void init()
{
    edge.clear();
    result = 0;
    for(int i = 1;i<=500;++i)
    {
        selected[i] = false;
        p[i] = -1;
        isTree[i] = 1;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    T = 0;
    while(true)
    {
        init();

        T++;
        cin>>n>>m;

        if(n == 0 && m == 0)
        {
            break;
        }

        for(int i = 1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            edge.push_back({a,b});
        }

        for(auto &e : edge)
        {
            if(find(e.first) != find(e.second))
            {
                if(isTree[find(e.first)] == 1 && isTree[find(e.second)] == 1)
                {
                    merge(e.first,e.second);
                    isTree[find(e.first)] = 1;
                }
                else
                {
                    merge(e.first,e.second);
                    isTree[find(e.first)] = -1;
                }
            }
            else
            {
                merge(e.first,e.second);
                isTree[find(e.first)] = -1;
            }
        }

        for(int i = 1;i<=n;++i)
        {
            if(isTree[find(i)] == 1 && selected[find(i)] == false)
            {
                selected[find(i)] = true;
                result++;
            }
        }

        cout<<"Case "<<T<<": ";
        if(result == 0)
        {
            cout<<"No trees.\n";
        }
        else if(result == 1)
        {
            cout<<"There is one tree.\n";
        }
        else
        {
            cout<<"A forest of "<<result<<" trees.\n";
        }


    }



    return 0;
}