class Solution {
public:
//     int maxP(int ind , int buy ,vector<int>& prices,vector<vector<int>>& dp)
//     {
//         int n = prices.size();
//         if(ind == n) return 0;
//         int profit = 0;
        
//         if(dp[ind][buy] != -1) return dp[ind][buy];
        
//         if(buy)
//         {
//             profit = max(-prices[ind] + maxP(ind+1,0,prices,dp),
//                          maxP(ind+1,1,prices,dp));
//         }
//         else
//         {
//             profit = max(prices[ind] + maxP(ind+1,1,prices,dp),
//                          maxP(ind+1,0,prices,dp));
//         }
        
//         return dp[ind][buy] = profit;
        
//     }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // vector<int>ahead(2,0),curr(2,0);
        // dp[n][0] = dp[n][1] = 0;
        int aheadBuy,aheadNotBuy,currBuy,currNotBuy;
        aheadBuy = aheadNotBuy = 0 ;
        for(int ind = n-1 ; ind >= 0 ;ind--)
        {
            currNotBuy = max(prices[ind] + aheadBuy,aheadNotBuy);
            currBuy = max(-prices[ind] + aheadNotBuy,aheadBuy);
            
            
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};