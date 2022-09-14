#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];
int st;

void func(int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    if (cur == 0)
    {
        st = 0;
    }
    else if (cur != 0)
    {
        st = st + 1;
    }

    for (int i = st; i < n; i++)
    {
        if (isused[i] == 1) continue;

        isused[i] = 1;

        num[cur] = arr[i];
        func(cur + 1);

        isused[i] = 0;
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    func(0);
}