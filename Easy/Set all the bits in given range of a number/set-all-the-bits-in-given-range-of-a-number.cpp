//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setAllRangeBits(int x , int l , int r) {
        // code here
        for(int i = l ; i <= r ; i++)
        {
            int mask = 1 << (i-1);
            x = x | mask;
        }
        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.setAllRangeBits(N,L,R) << endl;
    }
    return 0;
}
// } Driver Code Ends