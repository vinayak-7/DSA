//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        string str = "";
        stack<char> stack;
        stack.push(s[0]);
        for(int i = 1 ; i < s.length() ; i++)
        {
            if(stack.top() != s[i])
            {
                stack.push(s[i]);
            }
        }
        
        while(!stack.empty())
        {
            str += stack.top();
            stack.pop();
        }
        reverse(str.begin(),str.end());
        return str;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends