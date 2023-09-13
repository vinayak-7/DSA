//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // int count(int i , int j , string& s1 , string& s2 , vector<vector<int>> &dp)
    // {
    //     if(i < 0) return j + 1;
    //     if(j < 0) return i + 1;
        
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     if(s1[i] == s2[j]) return dp[i][j] = count(i-1,j-1,s1,s2,dp);
    //     return dp[i][j] = 1 + min(count(i-1,j,s1,s2,dp),min(count(i,j-1,s1,s2,dp),count(i-1,j-1,s1,s2,dp)));
    // }
    
    int editDistance(string s1, string s2) {
        // Code here
        int n = s1.size();
	    int m = s2.size();
	    
	    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j] = j;
        }
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2] = dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = 1 + min(dp[ind1-1][ind2],min(dp[ind1][ind2-1],dp[ind1-1][ind2-1]));
            }
        }
        
        // int k = dp[n][m];
	    return dp[n][m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends