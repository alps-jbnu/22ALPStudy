#include <bits/stdc++.h>

using namespace std;

int building[80001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    long long result=0;
    int cnt = 0;
    int N;
    stack<int> stack;

    cin>>N;
    
    for(int i = 1;i<=N;++i)
    {//빌딩들 왼쪽부터 입력
        cin>>building[i];
    }

    for(int i = 1;i<=N;++i)
    {// i번째 빌딩이 1 ~ i-1 번째 빌딩들 중에 몇 개의 빌딩들에게 보여질 수 있는지
        while(!stack.empty() && building[stack.top()] <= building[i])
        {
            stack.pop();
        }
        result += stack.size();
        stack.push(i);
    }

    //아니 근데 나는 이 풀이도 문제가 전혀 없다고 생각하는데 AC가 안나오니 문제가 있는거겠지
    // stack.push(1);
    // for(int i = 2;i<=N;++i)
    // {
    //     if(building[i-1] <= building[i])
    //     {
    //         while(!stack.empty())
    //         {
    //             if(building[stack.top()] <= building[i])
    //             {
    //                 result  += (i - stack.top() - 1);
    //                 stack.pop();
    //             }
    //             else
    //             {
    //                 break;
    //             }
    //         }
    //     }
    //     stack.push(i);
    // }
    // while(!stack.empty())
    // {
    //     result += cnt;
    //     stack.pop();
    //     ++cnt;
    // }

    cout<<result<<"\n";

}