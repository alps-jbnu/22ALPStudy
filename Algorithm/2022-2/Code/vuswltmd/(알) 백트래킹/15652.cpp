#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int n, s;
int arr[10];
bool isused[10];
//int cnt = 0;

void func(int cur)
{
    if(cur == s)
    {
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 1;
    if (cur != 0) st = arr[cur - 1];

    for (int i = st; i <= n; i++)
    {
        if (isused[i] == 1) continue;

        //isused[i] = 1;
        arr[cur] = i;

        func(cur + 1);
        //isused[i] = 0;
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    func(0);
}