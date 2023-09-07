//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    // {
    //     if( j < 0 || j >= mat[0].size()) return -1e8;
        
    //     if(i == 0) return mat[0][j];
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int up = mat[i][j] + f(i-1,j,mat,dp);
    //     int ldiag = mat[i][j] + f(i-1,j-1,mat,dp);
    //     int rdiag = mat[i][j] + f(i-1,j+1,mat,dp);
        
    //     return dp[i][j] = max(up , max(ldiag,rdiag));
    // }
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
        // int m = mat[0].size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> prev(n);
        int maxi = -1e8;
        for(int j = 0 ; j < n ; j++)
        {
            prev[j] = mat[0][j];
        }
        
        for(int i = 1 ; i < n ; i++)
        {
            vector<int> curr(n);
            for(int j = 0 ; j < n ; j++)
            {
                int ldiag = -1e8 , rdiag = -1e8;
                
                int up = mat[i][j] + prev[j];
                if(j<n-1) rdiag = mat[i][j] + prev[j+1];
                if(j>0) ldiag = mat[i][j] + prev[j-1];
                
                curr[j] = max(up , max(ldiag,rdiag));
            }
            prev = curr;
        }
        for(int i = 0 ; i < n ; i++)
        {
            maxi = max(maxi,prev[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends