#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

pair<long long, long long> arr[10000000];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr, arr + n);

    long long count = 0;

    long long st = arr[0].first;
    long long ed = arr[0].second;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].first <= ed && arr[i].second >= ed)
        {
            ed = arr[i].second;
        }
        else if(arr[i].first > ed)
        {
            count = count + (ed - st);
            st = arr[i].first;
            ed = arr[i].second;
        }
    }

    count = count + ed - st;
    
    cout << count;
}