#include <iostream>
using namespace std;

int a[2000001]={};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t, x, ans=0;
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> t;
    a[t]++;
  }

  cin >> x;
  for (int i = 1; i < (x+1)/2; ++i) {
    if (a[i]==1 && a[x-i]==1) ans++;
  }
  cout << ans;
}
