//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            int i = 0,j = 0,m1 = -1,m2 = -1;
            int sz = n + 1;
            while(sz--)
            {
                m1 = m2;
                if(i == n) 
                {
                    m2 = ar2[0];
                    break;
                    
                }
                else if(j == n) 
                {
                    m2 = ar1[0];
                    break;
                    
                }
                if(ar1[i] <= ar2[j]) m2 = ar1[i++];
                else m2 = ar2[j++];
            }
            return m1 + m2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends