#include <bits/stdc++.h>

using namespace std;

int A[1000001];
int result[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    stack<int> stack;
    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>A[i];
    }

    for(int i = 1;i<N;++i)
    {
        if(A[i] < A[i+1])
        {//A(i) 보다 더 큰 수가 오른쪽에 바로 존재한다면 : 오른쪽의 수가 A(i)의 오큰수 이다
            result[i] = A[i+1];
            while(!stack.empty())
            {//아직 오큰수가 정해지지 않은 k번 째 수들은 스택에 들어있고, A(i+1)이 스택의 수들 보다 크다면 그들의 오큰수가 된다
                if(A[stack.top()] < A[i+1])
                {
                    result[stack.top()] = A[i+1];
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
        }
        else
        {//오른쪽에 더 작은 수가 왔다면, i번 째 수는 아직 자신의 오큰수가 없다
            stack.push(i);
        }
    }
    result[N] = -1;//마지막 수는 항상 오큰수가 -1이다
    while(!stack.empty())
    {
        result[stack.top()] = -1;
        stack.pop();
    }

    for(int i = 1;i<=N;++i)
    {
        cout<<result[i]<<" ";
    }

}