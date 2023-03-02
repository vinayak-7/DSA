//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        int lastOcc = -1;
        for(int i = 32; i >= 0 ; i--)
        {
            if((1<<i)&n)
            {
                if(lastOcc == -1)
                {
                    lastOcc = i;
                }
                else if(lastOcc-i == 2)
                {
                    n = n&(~(1<<i));
                    lastOcc = -1;
                }
            }
            else
            {
                lastOcc = -1;
            }
        }
        
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int query;
        cin >> query;
        int ans = sol.noConseBits(query);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends