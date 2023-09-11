//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum = 0;
        for (int i = 0; i < n; i++) 
        {
            totSum += arr[i];
        }
        if(totSum - d < 0 || (totSum - d)%2) return false;
    
        int tar = (totSum-d)/2;
        int mod = 1e9+7;
        
        vector<vector<int>> dp(n,vector<int>(tar + 1 , 0));
        
        if (arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0] != 0 && arr[0] <= tar) dp[0][arr[0]] = 1;
        for(int ind = 1 ; ind < n ; ind++)
        {
            for(int sum = 0 ; sum <= tar ; sum++)
            {
                int not_take = dp[ind-1][sum];
                int take = 0; 
                if(arr[ind] <= sum) take = dp[ind-1][sum-arr[ind]];
                
                dp[ind][sum] = (take + not_take)%mod;
            }
            
        }
        return dp[n-1][tar];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends