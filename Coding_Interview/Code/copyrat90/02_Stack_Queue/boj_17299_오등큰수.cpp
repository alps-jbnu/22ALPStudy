#include <bits/stdc++.h>
using namespace std;

array<int,1000001> F = {0,};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<int> A(N);
    for (int& a : A)
    {
        cin >> a;
        F[a]++;
    }

    vector<int> NGF(N,-1);

    // idx 를 저장하는 스택
    stack<int> st;
    // O(N)
    for (int i=N-1;i>=0;--i)
    {
        // 총합 N번까지 st.pop() 일어남
        while (!st.empty() && F[A[st.top()]] <= F[A[i]])
            st.pop();
        
        if (!st.empty())
            NGF[i] = A[st.top()];

        // N번 st.push() 일어남
        st.push(i);
    }

    for (int ngf : NGF)
        cout << ngf << ' ';
}
