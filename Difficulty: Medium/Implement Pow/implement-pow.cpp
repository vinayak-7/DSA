//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        double ans = 1.0;
        long long exp = abs((long long)e); // Handle edge case when e = INT_MIN
        
        while (exp > 0) {
            if (exp % 2 == 1) { // If exponent is odd
                ans *= b;
            }
            b *= b; // Square the base
            exp /= 2; // Divide exponent by 2
        }
        
        return (e >= 0) ? ans : 1.0 / ans;
    }
};


//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends