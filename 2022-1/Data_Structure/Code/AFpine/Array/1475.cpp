#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string s;
    int res69=0;
    int res=0;
    int value69=0;
    int value=0;
    int result;

    cin>>N;
    s = to_string(N);

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

    for(int i = 0;i<10;++i)
    {
        if(i != 6 && i!= 9 && arr[i] > res)
        {
            res = arr[i];
            value = i;
        }
    }

    if(arr[6] > arr[9])
    {
        res69 = arr[6];
        value69 = 6;
    }
    else
    {
        res69 = arr[9];
        value69 = 9;
    }

    if(res > res69)
    {
        result = res;
    }
    else
    {
        if(value69 == 6)
        {
            result = arr[9];
            result = result + ceil((arr[6]-arr[9])/2.0);
            if(result < res)
            {
                result = arr[6];
            }
        }
        else
        {
            result = arr[6];
            result = result + ceil((arr[9]-arr[6])/2.0);
            if(result < res)
            {
                result = arr[9];
            }
        }
    }

    cout<<result<<"\n";



}