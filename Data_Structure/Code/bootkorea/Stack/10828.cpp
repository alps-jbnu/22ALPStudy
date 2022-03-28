#include <iostream>
#include <stack>
using namespace std;

int N;

int main(void)
{
    cin >> N;
    stack<int> st;

    while (N--) {
        string str;
        cin >> str;

        if (str == "push") {
            int num;
            cin >> num;
            st.push(num);
        }

        else if (str == "pop")
        {
            if (!st.empty()) {
                cout << st.top() << "\n";
                st.pop();
            }
            else
                cout << "-1" << "\n";
        }

        else if (str == "size")
        {
            cout << st.size() << "\n";
        }

        else if (str == "empty")
        {
            cout << st.empty() << "\n";
        }

        else if (str == "top")
        {
            if (!st.empty())
                cout << st.top() << "\n";
            else
                cout << "-1" << "\n";
        }
    }
}