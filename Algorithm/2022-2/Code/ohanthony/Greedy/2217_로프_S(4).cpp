#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int rope[100005];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> rope[i];

    sort(rope, rope + n, cmp);

    int result = 0;
    for(int i = 1; i <= n; i++){
        result = max(result, i*rope[i-1]);
    }

    cout << result;
    return 0;
}