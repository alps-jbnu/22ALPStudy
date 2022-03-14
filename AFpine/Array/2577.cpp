#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,B,C;
    string s;
    cin>>A>>B>>C;

    A = A*B*C;
    s = to_string(A);

    for(int i = 0;i<s.size();++i)
    {
        switch(s[i])
        {
            case '0':
                ++arr[0];
                break;
            case '1':
                ++arr[1];
                break;
            case '2':
                ++arr[2];
                break;
            case '3':
                ++arr[3];
                break;
            case '4':
                ++arr[4];
                break;
            case '5':
                ++arr[5];
                break;
            case '6':
                ++arr[6];
                break;
            case '7':
                ++arr[7];
                break;
            case '8':
                ++arr[8];
                break;
            case '9':
                ++arr[9];
                break;
        }
    }
    for(auto x : arr)
    {
        cout<<x<<"\n";
    }
}