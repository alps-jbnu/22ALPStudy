#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b)
{
    // a, b 길이가 같은 경우 사전순으로 정렬
    if(a.length() == b.length())
    {
        return a < b;
    }
    else return a.length() < b.length(); // 그 외 경우 길이 오름차순으로 정렬
}

string str[20005];
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> str[i];
    
    sort(str, str + n, compare);
    
    for(int i = 0; i < n; i++)
    {
        if(str[i] == str[i-1]) continue;
        cout << str[i] << "\n";
    }
    return 0;
}
/*
정렬 알고리즘 응용 문제
sort() 함수에서 compare 함수를 만들어서 세부 조건을 구성
*/