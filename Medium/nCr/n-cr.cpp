//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define mod (int)(1e9+7)
    int f(int n,int r,vector<vector<int>>& dp)
    {
        if(n<r) return 0;
        if(r==0) return 1;
        if(dp[n][r]!=-1) return dp[n][r];
        return dp[n][r]=(f(n-1,r-1,dp)+0LL+f(n-1,r,dp))%mod;
    }
    int nCr(int n, int r){
        vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
        return f(n,r,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends