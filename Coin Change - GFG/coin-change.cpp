//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int f(int ind , int target ,int nums[] , vector<vector<long long int>> &dp )
	{
	    
	    if(ind == 0)
	    {
	        if(target % nums[ind] == 0) return 1;
	        else return 0;
	    }
	    if(dp[ind][target] != -1) return dp[ind][target];
	    long long int not_take = 0 + f(ind-1,target,nums,dp);
	    long long int take = 0;
	    if(nums[ind] <= target) 
	    {
	        take = f(ind,target - nums[ind],nums,dp);
	    }
	    
	    return dp[ind][target] = take + not_take;
	}
    long long int count(int coins[], int n, int amount) {

        // code here.
        vector<vector<long long int>>dp(n,vector<long long int>(amount+1,-1));
	    long long int ans = f(n-1,amount,coins,dp);
	    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends