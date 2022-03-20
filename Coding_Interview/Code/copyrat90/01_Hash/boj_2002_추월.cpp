#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin>>N;
    unordered_map<string,int> carId;
    for (int i=0;i<N;++i)
    {
        string tmp; cin>>tmp;
        carId.insert({tmp, i});
    }

    vector<int> A(N);
    for (int i=0;i<N;++i)
    {
        string tmp; cin>>tmp;
        A[i]=carId[tmp];
    }

    int ans = 0;
    for (int i=0;i<N;++i)
        for (int k=i+1;k<N;++k)
            if (A[i] > A[k])
            {
                ++ans;
                break;
            }

    cout <<ans;
}
