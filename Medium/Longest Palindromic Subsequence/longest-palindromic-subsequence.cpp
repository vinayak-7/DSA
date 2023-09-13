//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int fun(int i , int j , string& s1 , string& s2 , vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + fun(i-1,j-1,s1,s2,dp);
        
        else return dp[i][j] = max(fun(i-1,j,s1,s2,dp), fun(i,j-1,s1,s2,dp));
    }
    int longestPalinSubseq(string str) {
        //code here
        string temp = str;
        reverse(temp.begin(),temp.end());
        int n = temp.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return fun(n-1,n-1,str,temp,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends