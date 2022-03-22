#include <iostream>
#include <string>
using namespace std;

int arr[2][26], res;
string s1, s2;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  cin>>s1>>s2;
  for(char c : s1)
    arr[0][c-'a']++;
  
  for(char c : s2)
    arr[1][c-'a']++;
  
  for(int i=0; i<26; i++)
    res += abs(arr[0][i]-arr[1][i]);
  
  cout << res;
}