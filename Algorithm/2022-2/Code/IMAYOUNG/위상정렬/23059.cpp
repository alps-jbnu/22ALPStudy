#include <bits/stdc++.h>
#define MAX 400000
using namespace std;
typedef pair<int, int> pi;
 
unordered_map<int, string> intToString; //인덱스 기준 문자열
unordered_map<string, int> stringToInt; //문자열 기준 인덱스 
vector<int> graph[MAX], ans[MAX];
int conn[MAX]; //연결 관련..
int N, idx;
 
bool cmp(int a, int b) {
    return intToString[a] < intToString[b];
}
 
void print() { //우선순위가 낮은 배열부터 출력 
    for (int i = 0; ; i++) {
        if (!ans[i].size()) return;
 
        sort(ans[i].begin(), ans[i].end(), cmp);
        for (int j = 0; j < ans[i].size(); j++) {
            cout << intToString[ans[i][j]] << '\n';
        }
    }
}
 
void func() {
    queue<pi> q;
    for (int i = 0; i < idx; i++) { //위상정렬로 순서 찾기 .
        if (!conn[i]) {
            q.push({ i,0 });
            ans[0].push_back(i);
        }
    }
 
    for (int t = 0; t < idx; t++) { //순서가 안된다면.. 즉 아이템을 구입하지 못하면 -1출력 
        if (q.empty()) {
            cout << "-1\n";
            return;
        }
 
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
 
        for (int i = 0; i < graph[x].size(); i++) {
            int next = graph[x][i];
 
            conn[next]--;
 
            if (!conn[next]) { 
                q.push({ next, cnt + 1 });
                ans[cnt + 1].push_back(next);
            }
        }
    }
 
    print();
}
 
int main() {
    cin.tie(0); 
    ios::sync_with_stdio(0);
 
    string str1, str2;
    cin >> N;
    for (int i = 0; i < N; i++) { //입력 받기 
        cin >> str1 >> str2;
 
//stringTolnt에서 str1문자가 있다면 
//그 문자와 인덱스를 삽입한다. 
//해당 문자열에 대한 인덱스 값을 맵에 넣는다.
        if (stringToInt.find(str1) == stringToInt.end()) { //문자열에 대한 인덱스 값을 구함.
            stringToInt.insert({ str1, idx });
            intToString.insert({ idx++, str1 });
        }
        if (stringToInt.find(str2) == stringToInt.end()) {
            stringToInt.insert({ str2, idx });
            intToString.insert({ idx++, str2 });
        }
 
        int a = stringToInt[str1];
        int b = stringToInt[str2];
        graph[a].push_back(b);
        conn[b]++;
    }
    func();
 
    return 0;
}
