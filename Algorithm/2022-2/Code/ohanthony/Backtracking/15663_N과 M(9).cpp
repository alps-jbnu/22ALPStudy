#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int n, m;
int num[10];
int arr[10];
bool isused[10];

void func(int k){
    if(k == m){ // base contion
        for(int i = 0; i < m; i++) cout << arr[i] << ' '; 
        cout << '\n';
        return ;
    }

    int temp = 0;
    for(int i = 0; i < n; i++){
        if(!isused[i] && temp != num[i]){
            isused[i] = true;
            arr[k] = num[i];
            temp = arr[k];
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> num[i];
    sort(num, num+n);

    func(0);
    return 0;
}