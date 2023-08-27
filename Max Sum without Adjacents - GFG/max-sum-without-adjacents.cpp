//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    dp[0] = arr[0];
	    for(int ind = 1 ; ind < n ; ind++)
	    {
	        int pick = arr[ind];
	        if(ind>1) pick += dp[ind-2];
	        int notPick = 0 + dp[ind-1];
	        dp[ind] = max(pick , notPick);
	    }
	    return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends