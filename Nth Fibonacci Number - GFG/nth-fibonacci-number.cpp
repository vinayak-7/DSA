//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int mod = 1000000007;
        int dp[] = {1, 1};
        
        int i = 3;
        while(i <= n) {
            int temp = dp[1];
            dp[1] = (dp[1] + dp[0]) % mod;
            dp[0] = temp;
            i++;
        }
        
        return dp[1] % 1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends