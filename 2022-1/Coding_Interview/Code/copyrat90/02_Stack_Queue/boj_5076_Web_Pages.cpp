#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
constexpr bool ndebug = false;
#else
constexpr bool ndebug = true;
#endif

#define debugf(...) if constexpr (!ndebug) {printf("[DEBUG] "); printf(__VA_ARGS__);}

int main()
{
    if constexpr (ndebug)
        cin.tie(0)->sync_with_stdio(0);

    string input;
    while (getline(cin, input))
    {
        if (input == "#")
            break;
        
        bool legal = true;
        bool parsingTag = false;
        bool foundTagName = false;
        bool closing = false;
        string tag;
        stack<string> st;
        for (int i=0;i<input.size();++i)
        {
            const char& ch = input[i];
            if (parsingTag)
            {
                if (ch == '>')
                {
                    parsingTag = false;
                    foundTagName = true;
                    debugf("found tag : %s\n", tag.c_str());
                    // self closing
                    if (input[i-1] == '/')
                    {
                        debugf("Self closing tag, do nothing!\n");
                    }
                    else if (closing)
                    {
                        if (st.empty() || st.top() != tag)
                        {
                            legal = false;
                            break;
                        }
                        debugf("pop : %s\n", st.top().c_str());
                        st.pop();
                    }
                    else
                    {
                        st.push(tag);
                        debugf("push : %s\n", st.top().c_str());
                    }
                    tag.clear();
                }
                else if (ch == ' ')
                {
                    foundTagName = true;
                    debugf("found tag : %s\n", tag.c_str());
                }
                if (!foundTagName)
                    tag += ch;
            }
            else
            {
                if (ch == '<')
                {
                    parsingTag = true;
                    foundTagName = false;
                    if (input[i+1] == '/')
                    {
                        closing = true;
                        ++i;
                    }
                    else
                        closing = false;
                }
            }
        }

        if (!st.empty())
            legal = false;
        
        if (legal)
            cout << "legal\n";
        else
            cout << "illegal\n";
    }
}
