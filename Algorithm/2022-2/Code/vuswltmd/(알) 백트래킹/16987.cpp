#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int n;
pair<int, int> egg[10];

int mx = 0;
int ans = 0;

void func(int cur)
{
    if (cur == n)
    {
        if (mx < ans)
        {
            mx = ans;
        }
        return;
    }
    if (egg[cur].first <= 0 || ans == n - 1)
    {
        func(cur + 1);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (egg[i].first <= 0 || i == cur) continue; //내가 날 깰수는 없으니

        egg[cur].first -= egg[i].second;
        egg[i].first -= egg[cur].second;
        if (egg[cur].first <= 0) ans++;
        if (egg[i].first <= 0) ans++;
        
        func(cur + 1);
        
        if (egg[cur].first <= 0) ans--;
        if (egg[i].first <= 0) ans--;
        egg[cur].first += egg[i].second;
        egg[i].first += egg[cur].second;
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //계란을 충돌시키면 상대 계란의 무게만큼 계란의 내구도가 깎임
    // 깨진 계란이 하나라도 없으면 넘어가기

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> egg[i].first;   //내구도
        cin >> egg[i].second;  //무게
    }

    func(0);

    cout << mx;
}