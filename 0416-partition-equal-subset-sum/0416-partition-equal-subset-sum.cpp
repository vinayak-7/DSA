class Solution {
public:
    bool check(int ind , int sum , vector<int>& arr,vector<vector<int>> &dp)
    {
        if(sum == 0) return true;
        if(ind == 0) return (arr[ind] == sum);
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        bool not_take = check(ind-1 , sum , arr,dp);
        bool take = false;
        if(sum >= arr[ind])
        {
            take = check(ind-1 , sum - arr[ind],arr,dp);
        }
        
        return dp[ind][sum] = take||not_take;
    }
    bool canPartition(vector<int>& arr) {
        int index = arr.size();
        int total_sum = 0;
        for(int i = 0 ; i < index ; i++)
        {
            total_sum += arr[i];
        }
        if(total_sum % 2 != 0) return 0;
        
        int target = total_sum/2;
        
        vector<vector<int>> dp(index,vector<int>(target+1,-1));

        return check(index-1,target,arr,dp);
    }
};