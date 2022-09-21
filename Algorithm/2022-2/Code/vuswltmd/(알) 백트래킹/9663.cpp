#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int n;
int cnt = 0;
bool isused1[35];
bool isused2[35];
bool isused3[35];


void func(int cur) // cur ดย x, iดย y
{
    if (cur == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isused1[i] == 1 || isused2[cur + i] == 1 || isused3[cur-i+n-1] == 1)
        {
            continue;
        }

        isused1[i] = 1;
        isused2[cur + i] = 1;
        isused3[cur - i + n - 1] = 1;

        func(cur + 1);

        isused1[i] = 0;
        isused2[cur + i] = 0;
        isused3[cur - i + n - 1] = 0;
    }
}


int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt;
}