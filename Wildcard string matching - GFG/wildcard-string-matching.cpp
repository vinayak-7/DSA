//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool f(int i , int j ,string& pattern,string& wild ,vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0)
        {
            for(int k = 0 ; k <= i ; k++)
            {
                if(wild[k] != '*') return false;
            }
            
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i] == wild[j] || wild[i] == '?')
        {
            return dp[i][j] = f(i-1,j-1,pattern,wild,dp);
        }
        if(wild[j] == '*') return dp[i][j] = f(i-1,j,pattern,wild,dp)||f(i,j-1,pattern,wild,dp);
        
    }
    bool match(string wild, string pattern)
    {
        // code here
        int n = pattern.size();
        int m = wild.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,pattern,wild,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends