//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    vector<int> longestIncreasingSubsequence(int n, vector<int>& a) {
        // Code here
        vector<int> dp(n,1),hash(n);
        int len = 1;
        int lastInd = 0;
        for(int ind = 0 ; ind < n ; ind++)
        {
            hash[ind] = ind;
           for(int prev = 0 ; prev < ind ; prev++)
           {
               if(a[prev] < a[ind] && 1 + dp[prev] > dp[ind] )
               {
                   dp[ind] = 1 + dp[prev];
                   hash[ind] = prev;
               }
           }
           if(dp[ind] > len)
           {
               len = dp[ind];
               lastInd = ind;
           }
        }
        
        vector<int> lis;
        lis.push_back(a[lastInd]);
        while(hash[lastInd] != lastInd)
        {
            lastInd = hash[lastInd];
            lis.push_back(a[lastInd]);
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends