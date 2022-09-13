#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int L;
int C;
//char alpa1[15]; // 자음
//char alpa2[15]; // 모음
//
//int alpa1_count = 0;
//int alpa2_count = 0;
char alpa[15];
int ind[15];
bool isused[15];

void func(int cur)
{
    if (cur == L)
    {
        bool mo = false;
        bool ja = false;
        int ja_count = 0;

        //자음2개 모음 1개인지 검사
        for (int i = 0; i < L; i++)
        {
            char a = alpa[ind[i]];
            if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
            {
                mo = true;
            }
            else
            {
                ja_count++;
                if (ja_count >= 2)
                {
                    ja = true;
                }
            }
        }

        if (mo == true && ja == true)
        {
            for (int i = 0; i < L; i++)
            {
                cout << alpa[ind[i]];
            }
            cout << '\n';
            return;
        }
    }
    int st = 0;
    if (cur != 0) st = ind[cur - 1] + 1;
    for (int i = st; i < C; i++)
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

    cin >> L >> C;

    /*for (int i = 0; i < C; i++)
    {
        char a;
        cin >> a;
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        {
            alpa1[alpa1_count] = a;
            alpa1_count++;
        }
        else
        {
            alpa2[alpa2_count] = a;
            alpa2_count++;
        }
    }*/

    for (int i = 0; i < C; i++)
    {
        cin >> alpa[i];
    }

    sort(alpa, alpa + C);

    func(0);
}