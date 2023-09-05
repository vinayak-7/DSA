class Solution {
public:
//     int f(int i, int j, vector<vector<int>> &mat,vector<vector<int>> &dp)
//     {
        
//         if(i == 0 && j == 0) return mat[0][0];
//         if(i < 0 || j < 0) return 1e9;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int up = mat[i][j] + f(i-1,j,mat,dp);
//         int left = mat[i][j] + f(i,j-1,mat,dp);
        
//         return dp[i][j] = min(up,left);
//     }
    int minPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> prev(m,0);
        
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0 ; i < n ; i++)
        {
            vector<int> curr(m,0);
            for(int j = 0 ; j < m ; j++)
            {
                if(i == 0 && j == 0) curr[j] = mat[i][j];
                else{
                    int up = mat[i][j];
                    if(i>0)up += prev[j];
                    else up += 1e9;
                    
                    int left = mat[i][j];
                    if(j>0)left += curr[j-1];
                    else left += 1e9;
                    
                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};