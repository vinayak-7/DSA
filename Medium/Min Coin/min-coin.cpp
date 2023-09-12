//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int ind , int target ,vector<int> &nums , vector<vector<int>> &dp )
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
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n = nums.size();
	    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
	    int ans = f(n-1,amount,nums,dp);
	    if(ans >= 1e9) return -1;
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends