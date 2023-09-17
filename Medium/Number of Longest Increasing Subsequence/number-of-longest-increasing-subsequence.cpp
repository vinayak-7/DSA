//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&nums) {
        // Code here
	    vector<int> dp(n,1),cnt(n,1);
        int len = 1;
        for(int ind = 0 ; ind < n ; ind++)
        {
           for(int prev = 0 ; prev < ind ; prev++)
           {
               if(nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind])
               {
                   dp[ind] = max(dp[ind] , 1 + dp[prev]);
                   cnt[ind] = cnt[prev];
               }
               else if(nums[prev] < nums[ind] && 1 + dp[prev] == dp[ind])
               {
                   cnt[ind] += cnt[prev];
               }
           }
           len = max(len , dp[ind]);
        }
        int count = 0;
        for(int ind = 0 ; ind < n ; ind++)
        {
            if(dp[ind] == len) count += cnt[ind];
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends