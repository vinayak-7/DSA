//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // int f(int i , int j , vector<vector<int>> &mat ,  vector<vector<int>> &dp)
    // {
    //     int mod = 1e9 + 7;
    //     if(i >= 0 && j >= 0 && mat[i][j] == 0) return 0;
    //     if(i == 0 && j == 0) return 1;
    //     if(i < 0 || j < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int up = f(i-1,j,mat,dp);
    //     int left = f(i,j-1,mat,dp);
        
    //     return dp[i][j] = (up + left)%mod;
    // }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp( n , vector<int> (m, -1));
        
        int mod = 1e9 + 7;
        for(long long i = 0 ; i < n ; i++)
        {
            for(long long j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 0) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
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
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends