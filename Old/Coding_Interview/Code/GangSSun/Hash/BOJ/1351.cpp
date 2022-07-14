#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long func(long long n){
    if(n==0) return 1;
    else if(m[n] != 0) return m[n];
    return m[n]=func(n/P)+func(n/Q);//주어진 점화식을 이용해 top-down방식의 dp 구현
}
int main(){

    cin>>N>>P>>Q;
    
    cout<<func(N)<<"\n";
}