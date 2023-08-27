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
	   // vector<int> dp(n,-1);
	    int prev = arr[0];
	    int prev2 = prev;
	    for(int ind = 1 ; ind < n ; ind++)
	    {
	        int pick = arr[ind];
	        if(ind>1) pick += prev2;
	        int notPick = 0 + prev;
	        int curr = max(pick , notPick);
	        prev2 = prev;
	        prev = curr;
	    }
	    return prev;
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