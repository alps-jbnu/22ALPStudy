#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> V, del;
    for(int i = 0; i <= n; i++) V.push_back(i);
    
    for(int i = 0; del.size() < n; i++){
        if(i%k == k-1) del.push_back(V[i]);
        else V.push_back(V[i]);
    }
    
    cout << "<";
    for(int i = 0; i < n; i++){
        if(i == n-1) cout << del[i];
        else cout << del[i] << ', ';
    }
    cout << ">";
}