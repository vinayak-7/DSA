//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int cnt = 0;
    stack<char> st;
    for(int i = 0 ; i < s.size() ; i++ )
    {
        if(s[i] == '{') st.push(s[i]);
        else if(!st.empty())
        {
            if(s[i] == '}' && st.top() == '{')st.pop();
        }
        else
        {
            st.push('{');
            cnt++;
        }
    }
    if(st.size() % 2 != 0) return -1;
    return cnt += st.size()/2;
}