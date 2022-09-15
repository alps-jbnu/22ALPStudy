#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int n, m;
int arr[10];
bool isused[10]; // 1이면 사용, 0이면 사용x

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';   
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (isused[i] == 0)
        {
            isused[i] = 1;
            arr[k] = i;
            func(k + 1);         
            isused[i] = 0;
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    func(0);
}