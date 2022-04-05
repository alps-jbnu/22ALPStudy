#include <bits/stdc++.h>
using namespace std;
 
using namespace std;
 
const int MAX = 1001;
int N, M, V;
int visited[MAX];
int mat[MAX][MAX];
queue<int> q;
 
void BFS( int s ) {
 
    q.push(s);
    visited[s] = 1;
 
    while (!q.empty()) {
        s = q.front();
        cout << s << " ";
        q.pop();
        for ( int i = 1 ; i <= N ; ++i) {
            if ( mat[s][i] == 1 && visited[i] == 0 ) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
 
void DFS(int v) {
    visited[v] = 1;
    cout << v << " ";
    for ( int i = 1 ; i <= N ; ++i ) {
        if ( mat[v][i] == 1 && visited[i] == 0 )
            DFS(i);
    }
}
 
void reset() {
    for ( int i = 1; i <= N ; i++ ) {
        visited[i] = 0;
    }
    cout << endl;
}
 
int main (void) {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int first, second;
    cin >> N >> M >> V;
 
    for ( int i = 0 ; i < M ; i++ ) {
        cin >> first >> second;
        mat[first][second] = 1;
        mat[second][first] = 1;
    }
 
    DFS(V);
    reset();
    BFS(V);
 
    return 0;
}