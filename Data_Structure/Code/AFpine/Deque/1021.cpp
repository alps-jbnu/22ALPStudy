#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int cnt=0;
    int leftnum, rightnum;
    deque<int> dq1;
    deque<int> dq2;

    cin>>N>>M;

    for(int i = 1;i<=N;++i)
    {
        dq1.push_back(i);
        dq2.push_back(i);
    }
    for(int i = 0;i<M;++i)
    {
        int num;
        int temp;
        leftnum=0;
        rightnum=0;

        cin>>num;

        while(dq1.front() != num)
        {
            temp = dq1.front();
            dq1.pop_front();
            dq1.push_back(temp);
            ++leftnum;
        }
        dq1.pop_front();
        while(dq2.front() != num)
        {
            temp = dq2.back();
            dq2.pop_back();
            dq2.push_front(temp);
            ++rightnum;
        }
        dq2.pop_front();
        if(leftnum>rightnum)
        {
            cnt += rightnum;
            dq1 = dq2;
        }
        else
        {
            cnt += leftnum;
            dq2 = dq1;
        }
    }

    cout<<cnt<<"\n";

}