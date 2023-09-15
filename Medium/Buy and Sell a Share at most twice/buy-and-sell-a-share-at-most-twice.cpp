//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&prices){
    //Write your code here..
    int n = prices.size();  
    vector<vector<int>> dp(n+1,vector<int>(5,0));
    for(int ind = n-1 ; ind >= 0 ; ind--)
    {
        dp[ind][0] = 0;
    }
    for(int trans = 0 ; trans <= 3 ; trans++)
    {
        dp[0][trans] = 0;
    }
    for(int ind = n-1 ; ind >= 0 ; ind--)
    {
        for(int trans = 0 ; trans <= 3 ; trans++)
        {
            if(trans % 2 == 0)
            {
                dp[ind][trans] = max(-prices[ind] + dp[ind+1][trans+1], dp[ind+1][trans]);
            }
            else
            {
                dp[ind][trans] = max(prices[ind] + dp[ind+1][trans+1], dp[ind+1][trans]);
            }
        }
    }
    return dp[0][0];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends