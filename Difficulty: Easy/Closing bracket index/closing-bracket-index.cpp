//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closing (string s, int pos)
        {
        	//code here.
        	if(s[pos]==']') return -1;
            if(s[pos]!='[') return pos;
            
            stack<char> st;
            int cnt=0;
            
            for(int i=0;i<s.size();i++){
                if(i>=pos && s[i]=='['){
                    st.push(s[i]);
                }
                else if(s[i]==']' && !st.empty()){
                    st.pop();
                    if(st.empty())
                    return i;
                }
            }
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int pos; cin >> pos;
        Solution ob;
		cout <<ob.closing (s, pos) << '\n';
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends