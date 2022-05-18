#include <bits/stdc++.h>
using namespace std;

int sol(int n, int r, int c){
  if(n == 0) return 0;
  int haf = 1<<(n-1);
  if(r < haf && c < haf return sol(n-1, r, c);
  if(r < haf && c >= haf) return haf*haf + sol(n-1, r, c-haf);
  if(r >= haf && c < haf) return 2*haf*haf + sol(n-1, r-haf, c);
  return 3*haf*haf + sol(n-1, r-haf, c-haf);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r, c;
  cin >> n >> r >> c;
  cout << sol(n, r, c);
}