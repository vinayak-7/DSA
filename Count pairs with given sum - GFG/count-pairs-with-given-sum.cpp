//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++)
        {
            int b = arr[i];
            int a = k - b;
            
            ans += mp[a];
            mp[b]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends