//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int f(int ind , int target ,int nums[] , vector<vector<int>> &dp )
	{
	    
	    if(ind == 0)
	    {
	        if(target % nums[ind] == 0) dp[ind][target] = target/nums[ind];
	        else dp[ind][target] = 1e9;
	    }
	    if(dp[ind][target] != -1) return dp[ind][target];
	    int not_take = 0 + f(ind-1,target,nums,dp);
	    int take = 1e9;
	    if(nums[ind] <= target) 
	    {
	        take = 1 + f(ind,target - nums[ind],nums,dp);
	    }
	    
	    return dp[ind][target] = min(take,not_take);
	}
	int minCoins(int coins[], int n, int amount) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
	    int ans = f(n-1,amount,coins,dp);
	    if(ans >= 1e9) return -1;
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends