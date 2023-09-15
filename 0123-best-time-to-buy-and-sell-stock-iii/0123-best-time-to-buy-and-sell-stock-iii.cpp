class Solution {
public:
//     int maxP(int ind , int buy ,int cap ,vector<int>& prices,vector<vector<vector<int>>>& dp)
//     {
//         int n = prices.size();
//         if(ind == n) return 0;
//         if(cap == 0) return 0;
        
//         int profit = 0;
        
//         if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
//         if(buy)
//         {
//             profit = max(-prices[ind] + maxP(ind+1,0,cap,prices,dp),
//                          maxP(ind+1,1,cap,prices,dp));
//         }
//         else
//         {
//             profit = max(prices[ind] + maxP(ind+1,1,cap-1,prices,dp),
//                          maxP(ind+1,0,cap,prices,dp));
//         }
        
//         return dp[ind][buy][cap] = profit;
        
//     }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int buy = 0 ; buy <= 1 ; buy++)
        {
            for(int cap = 0 ; cap <= 2 ; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }
        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                dp[ind][buy][0] = 0;
            }
        }
        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                for(int cap = 1 ; cap <= 2 ;cap++)
                {
                    if(buy)
                    {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],
                                     dp[ind+1][1][cap]);
                    }
                    else
                    {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1],
                                     dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};