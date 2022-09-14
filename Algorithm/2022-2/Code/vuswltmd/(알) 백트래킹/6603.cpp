#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int num[15];
int arr[15];
int ind[15];
int num_count;
bool isused[15];

void func(int cur)
{
    if (cur == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << num[ind[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    int st = 0;
    if (cur != 0) st = ind[cur-1]+1;

    for (int i = st; i < num_count; i++)
    {
        if (isused[i] == 0)
        {
            isused[i] = 1;
            ind[cur] = i;
            func(cur + 1);
            isused[i] = 0;
        }
    }


}


int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        int k;
        cin >> k;
        num_count = k;

        if (k == 0)
        {
            return 0;
        }

        for (int i = 0; i < k; i++)
        {
            cin >> num[i];
        }

        func(0);
        cout << '\n';

        for(int i = 0; i < k; i++)
        {
            num[i] = 0;
        }
    }
}