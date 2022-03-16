#include <bits/stdc++.h>

using namespace std;

int tower[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    stack<int> s;       //왼쪽의 빌딩부터 삽입
    queue<int> q;

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>tower[i];
    }
    
    for(int i = N-1;i>=0;--i)
    {
        if(tower[i] > tower[i+1])   //왼쪽의 빌딩이 오른쪽보다 크면
        {   
            tower[i+1] = i;         //왼쪽 빌딩이 수신받는다
            while(!s.empty())       
            {
                if(tower[i] > tower[s.top()])
                {//왼쪽 빌딩이 스택에 들어있는 빌딩보다 크면
                    tower[s.top()] = i;
                    //스택에 들어있는 빌딩도 왼쪽빌딩에 송신한다
                    s.pop();
                }
                else
                {//스택의 가장 위에있는 빌딩이 스택에서 가장 작은 빌딩이므로
                //현재 가장 위에있는 빌딩보다 더 큰 빌딩들만 순서대로 들어있다
                    break;
                }
            }
        }
        else                        //오른쪽 빌딩이 왼쪽보다 더 크면
        {
            s.push(i+1);            //그 빌딩을 스택에 넣는다
            //이 상태에서 스택에 들어있는 빌딩은 아직 어디에 송신하는지 정해지지 않았다.
            //또한 스택에는 큰 빌딩이 먼저 들어온다.
        }
    }
    while(!s.empty())
    {
        tower[s.top()] = 0;
        s.pop();
    }

    for(int i = 1;i<=N;++i)
    {
        cout<<tower[i]<<" ";
    }

}