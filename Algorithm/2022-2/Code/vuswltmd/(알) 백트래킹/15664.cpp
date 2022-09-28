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
int ind[10];
bool isused[10];

void func(int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[ind[i]] << ' ';
        }
        cout << '\n';
        return;
        
    }

    int st = 0;
    if (cur != 0) st = ind[cur-1]+1;
    int tmp = 0;

    for (int i = st; i < n; i++)
    {
        if (isused[i] == 0 && tmp != arr[i])
        {
            isused[i] = 1;

            ind[cur] = i;
            tmp = arr[ind[cur]]; // 재귀함수에서 벗어나면서 tmp도 바뀌게 되었을 것임 
            
            func(cur + 1);       

            isused[i] = 0;
        }
        
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