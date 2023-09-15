//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        // code here
        vector<int> after(2*k+1,0);
        vector<int> curr(2*k+1,0);

        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            for(int trans = 2*k-1 ; trans >= 0 ; trans--)
            {
                if(trans % 2 == 0)
                {
                    curr[trans] = max(-prices[ind] + after[trans+1] , after[trans]);
                }
                else
                {
                    curr[trans] = max(prices[ind] + after[trans+1] , after[trans]);
                }
            }
            after = curr;
        }
        return after[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends