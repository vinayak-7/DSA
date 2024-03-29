//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        int mod = 1e9+7;
        vector<int> nums(n+1,0);
        nums[1] = 1;
        for(int i = 2 ; i <= n ; i++)
        {
            nums[i] = (nums[i-1] + nums[i-2])%mod;
        }
        
        return nums;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends