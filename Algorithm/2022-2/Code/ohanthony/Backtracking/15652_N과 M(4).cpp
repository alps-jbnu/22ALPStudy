#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int n, m;
int arr[10];

void func(int num){
    if(num == m){ // base contion
        for(int i = 0; i < m; i++) cout << arr[i] << ' '; 
        cout << '\n';
        return ;
    }

    int st = 1;
    if(num != 0) st = arr[num-1];
    for(int i = st; i <= n; i++){
        arr[num] = i;
        func(num+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    func(0);
    return 0;
}