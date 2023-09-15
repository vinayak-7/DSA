class Solution {
public:
    int maxP(int ind , int trans ,vector<int>& prices,vector<vector<int>>& dp)
    {
        int n = prices.size();
        if(ind == n || trans == 4) return 0;
        
        int profit = 0;
        
        if(dp[ind][trans] != -1) return dp[ind][trans];
        
        if(trans % 2 == 0)
        {
            profit = max(-prices[ind] + maxP(ind+1,trans+1,prices,dp),
                         maxP(ind+1,trans,prices,dp));
        }
        else
        {
            profit = max(prices[ind] + maxP(ind+1,trans+1,prices,dp),
                         maxP(ind+1,trans,prices,dp));
        }
        
        return dp[ind][trans] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return maxP(0,0,prices,dp);
    }
};