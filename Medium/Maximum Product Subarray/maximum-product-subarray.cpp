//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code here
	    if(n == 1) return nums[0];
	    long long prod = 1;
        long long maxProduct = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            prod *= nums[i];
            maxProduct = max(maxProduct , prod);
            
            if(prod == 0)
            {
                prod = 1;
            }
        }
        
        prod = 1; 
        
        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
            prod *= nums[i];
            maxProduct = max(maxProduct , prod);
            
            if(prod == 0)
            {
                prod = 1;
            }
        }
        return maxProduct;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends