//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int maxProfit(vector<int>& prices) {
    if(!prices.size()) 
    {
        return 0;
    }
    int n = prices.size();
    int maxProfit = 0;
    int left[n], right[n];
    int leftmin = prices[0], rightmax = prices[n-1];
    left[0] = 0; right[n - 1] = 0;                                     // because we can't make any profit with just 1 element
    int i,j;
    for(i = 1, j = n-2; i < n, j >= 0; i++, j--){
        leftmin  = min(leftmin, prices[i]);                            // find the minimum price till now
        left[i]  = max(left[i - 1], prices[i] - leftmin);              // max of selling today or skipping (previous max profit)
        rightmax = max(rightmax, prices[j]);                           // find the maximum price to the right
        right[j] = max(right[j + 1], rightmax - prices[j]);            // max of buying today or skipping
    }
    for(int i = 0; i < n; i++){
        maxProfit = max(maxProfit, left[i] + right[i]);
    }
    return maxProfit;
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