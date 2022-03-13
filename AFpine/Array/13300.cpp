#include <bits/stdc++.h>

using namespace std;

int arr[2][6];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;          //num of students
    double K;          //num of one room
    int S;          //0 is female, 1 is male
    int Y;          //year of student
    int result = 0;

    cin>>N>>K;
    
    for(int i = 0;i<N;++i)
    {
        cin>>S>>Y;
        arr[S][Y-1]++;
    }

    for(int i = 0;i<2;++i)
    {
        for(int j = 0;j<6;++j)
        {
            result += ceil(arr[i][j]/K);
        }
    }
    cout<<result<<"\n";

    return 0;

}