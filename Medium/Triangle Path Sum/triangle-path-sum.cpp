//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int i , int j , vector<vector<int>>& mat,vector<vector<int>>& dp)
    {
        int n = mat.size();
        if(i == n-1) return mat[n-1][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = mat[i][j] + f(i+1,j,mat,dp);
        int diag = mat[i][j] + f(i+1,j+1,mat,dp);
        
        return dp[i][j] = min(down,diag);
        
    }
    int minimizeSum(int n, vector<vector<int>>& mat) {
        // Code here
        vector<vector<int>> dp(n , vector<int>(n,-1));
        return f(0,0,mat,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends