//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if( j < 0 || j >= mat[0].size()) return -1e8;
        
        if(i == 0) return mat[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = mat[i][j] + f(i-1,j,mat,dp);
        int ldiag = mat[i][j] + f(i-1,j-1,mat,dp);
        int rdiag = mat[i][j] + f(i-1,j+1,mat,dp);
        
        return dp[i][j] = max(up , max(ldiag,rdiag));
    }
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi = -1e8;
        for(int j = 0 ; j < m ; j++)
        {
            maxi = max(maxi,f(n-1,j,mat,dp));
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