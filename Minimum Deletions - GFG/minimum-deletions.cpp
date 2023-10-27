//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lon_palin(string &S, int i, int j, int &n, vector<vector<int>>& dp){
        if(i > j){
            return 0;
        }
        else if(i == j){
            return 1;
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            if(S[i] == S[j]){
                return dp[i][j] = 2 + lon_palin(S, i+1, j-1, n, dp);
            }
            else{
                return dp[i][j] = max(lon_palin(S, i+1, j, n, dp), lon_palin(S, i, j-1, n, dp));
            }
        }
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n = S.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n - lon_palin(S, 0, n-1, n, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends