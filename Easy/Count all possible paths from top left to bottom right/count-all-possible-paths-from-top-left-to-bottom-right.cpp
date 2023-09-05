//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long f(int m , int n , vector<vector<long long>> &dp)
    {
        int mod = 1e9 + 7;
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        
        long long up = f(m-1,n,dp);
        long long left = f(m,n-1,dp);
        
        return dp[m][n] = (up + left)%mod;
    }
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<long long>> dp( m , vector<long long> (n, -1)); 
        return f(m-1,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends