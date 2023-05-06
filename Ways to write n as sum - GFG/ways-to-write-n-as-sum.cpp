//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
    int solve(int n,int i,vector<vector<int>>&dp)
    {   
        int mod = 1e9 + 7;
           
        if(n==0 or n==i) return 1;
        if(i>n or n<0) return 0;
        
        
        if(dp[n][i]!=-1) return dp[n][i]; 
        
        int take=solve(n-i,i,dp)%mod;
        int notTake=solve(n,i+1,dp)%mod;
        
        return dp[n][i]=(take+notTake)%mod;
    }
    int countWays(int n)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,1,dp)-1;
        
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends