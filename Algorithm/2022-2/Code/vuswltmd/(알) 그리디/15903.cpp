#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

long long arr[1001];
long long n;
long long m;
long long all_sum = 0;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    long long two_sum;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++)
    {
        sort(arr, arr + n);
        two_sum = arr[0] + arr[1];

        arr[0] = two_sum;
        arr[1] = two_sum;
    }

    for (int i = 0; i < n; i++)
    {
        all_sum = all_sum + arr[i];
    }

    cout << all_sum;
}