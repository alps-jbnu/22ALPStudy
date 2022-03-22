#include <iostream>
#include <queue>
using namespace std;

int N;

int main(void)
{
    cin >> N;
    queue<int> q;

    while (N--) {
        string str;
        cin >> str;

        if (str == "push") {
            int num;
            cin >> num;
            q.push(num);
        }

        else if (str == "pop")
        {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << "-1" << "\n";
        }

        else if (str == "size")
        {
            cout << q.size() << "\n";
        }

        else if (str == "empty")
        {
            cout << q.empty() << "\n";
        }

        else if (str == "front")
        {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << "-1" << "\n";
        }

        else if (str == "back")
        {
            if (!q.empty())
                cout << q.back() << "\n";
            else
                cout << "-1" << "\n";
        }
    }
}