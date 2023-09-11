//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int ind , int target , vector<int>& arr , vector<vector<int>> &dp)
	{
	    int mod = 1e9+7;
	    if(ind == 0)
	    {
	        if(arr[0] == 0 and target == 0) return 2;
	        if(target == 0 or target == arr[0]) return 1;
	        return 0;
	    }
	    if(dp[ind][target] != -1) return dp[ind][target];
	    
	    int not_taken = f(ind - 1 , target, arr, dp);
	    int taken = 0;
	    if(arr[ind] <= target) taken = f(ind - 1, target - arr[ind] , arr , dp);
	    
	    return dp[ind][target] = (taken + not_taken)%mod;
	}
    
	int perfectSum(int n, int tar, vector<int>& arr)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(tar + 1 , -1));
        
        return f(n-1,tar,arr,dp);
	}
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum = 0;
        for (int i = 0; i < n; i++) 
        {
            totSum += arr[i];
        }
        if(totSum - d < 0 || (totSum - d)%2) return false;
    
        return perfectSum(n,(totSum-d)/2,arr);
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