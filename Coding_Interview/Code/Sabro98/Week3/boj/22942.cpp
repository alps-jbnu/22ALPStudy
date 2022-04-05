#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAX = 2020002;

int N;
ll tree[4 * MAX];

int LEFT(int x) {
    return x * 2;
}

int RIGHT(int x) {
    return x * 2 + 1;
}
//void display(int start, int end, int node){
//    cout << "from " << start << " to " << end << " : " << tree[node] << endl;
//    if(start == end) return;
//    int mid = (start + end) / 2;
//    display(start, mid, LEFT(node));
//    display(mid + 1, end, RIGHT(node));
//}

ll calc(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return calc(start, mid, LEFT(node), left, right) + calc(mid + 1, end, RIGHT(node), left, right);
}

void update(int start, int end, int node, int idx, ll diff) {
    if (start > idx || end < idx) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, LEFT(node), idx, diff);
    update(mid + 1, end, RIGHT(node), idx, diff);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> A[200001];
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, r;
        cin >> x >> r;
        A[i] = {-r, x};
    }
    sort(A, A + N);

    for (int i=0; i<N; i++) {
        auto a = A[i];
        int x, r;
        x = a.second, r = -a.first;
        x += 1010001;
        int l = x - r, u = x + r;
        if (calc(0, MAX, 1, l, u) != 0){
            cout << "NO";
            exit(0);
        }
        update(0, MAX, 1, l, 1);
        update(0, MAX, 1, u, 1);
    }

    cout << "YES";

    return 0;
}