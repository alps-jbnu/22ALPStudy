#include <bits/stdc++.h>

//17071 Hide and Seek 5

using namespace std;

static const int INF = 100000000;

bool visited[2][500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,K;
    queue<int> subinQ;
    queue<int> timeQ;
    bool catchsis = false;
    int result;

    cin>>N>>K;

    subinQ.push(N);
    timeQ.push(0);
    visited[0][N] = true;

    while(!subinQ.empty())
    {
        int cur = subinQ.front();
        int time = timeQ.front();
        int sis = K + (time*(time+1)/2);
        int oddeven = time%2;       //0 is even, 1 is odd
        
        subinQ.pop();
        timeQ.pop();

        //cout<<cur<<" "<<sis<<"\n";

        if(sis > 500000)
        {
            continue;
        }
        if(cur == sis || visited[oddeven][sis] == true)
        {
            catchsis = true;
            result = time;
            break;
        }
        if(cur+1 <= 500000 && visited[(oddeven+1)%2][cur+1] == false)
        {
            visited[(oddeven+1)%2][cur+1] = true;
            subinQ.push(cur+1);
            timeQ.push(time+1);
        }
        if(cur-1 >= 0 && visited[(oddeven+1)%2][cur-1] == false)
        {
            visited[(oddeven+1)%2][cur-1] = true;
            subinQ.push(cur-1);
            timeQ.push(time+1);
        }
        if(cur*2 <= 500000 && visited[(oddeven+1)%2][cur*2] == false)
        {
            visited[(oddeven+1)%2][cur*2] = true;
            subinQ.push(cur*2);
            timeQ.push(time+1);
        }
    }

    if(catchsis)
    {
        cout<<result<<'\n';
    }
    else
    {
        cout<<"-1\n";
    }

    return 0;
}