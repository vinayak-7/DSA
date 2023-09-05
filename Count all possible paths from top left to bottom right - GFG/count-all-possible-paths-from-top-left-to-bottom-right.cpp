//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // long long f(int m , int n , vector<vector<long long>> &dp)
    // {
    //     int mod = 1e9 + 7;
    //     if(m == 0 && n == 0) return 1;
    //     if(m < 0 || n < 0) return 0;
    //     if(dp[m][n] != -1) return dp[m][n];
        
    //     long long up = f(m-1,n,dp);
    //     long long left = f(m,n-1,dp);
        
    //     return dp[m][n] = (up + left)%mod;
    // }
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<long long>> dp( m , vector<long long> (n, -1));
        int mod = 1e9 + 7;
        for(long long i = 0 ; i < m ; i++)
        {
            for(long long j = 0 ; j < n ; j++)
            {
                
                if(i == 0 && j == 0) dp[0][0] = 1;
                else
                {
                    long long up = 0;
                    long long left = 0;
                    if(i>0)up = dp[i-1][j];
                    if(j>0)left = dp[i][j-1];
                    dp[i][j] = (up + left)%mod;
                }
                
            }
        }
        return dp[m-1][n-1];
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