#include <iostream>
using namespace std;

int freq[26];
int main(void) {
    string s;
    cin >> s;
    for(auto c : s) {
        freq[c-'a']++;
    }
    for(int i = 0; i < 26; i++){
        cout << freq[i] << ' ';
    }
}