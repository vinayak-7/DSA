//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& a) {
        // Code here
        vector<int> dp(n,1),hash(n);
        int len = 1;
        int lastInd = 0;
        sort(a.begin(),a.end());
        for(int ind = 0 ; ind < n ; ind++)
        {
            hash[ind] = ind;
           for(int prev = 0 ; prev < ind ; prev++)
           {
               if(a[ind] % a[prev] == 0 && 1 + dp[prev] > dp[ind] )
               {
                   dp[ind] = 1 + dp[prev];
                   hash[ind] = prev;
               }
           }
           if(dp[ind] > len)
           {
               len = dp[ind];
               lastInd = ind;
           }
        }
        
        vector<int> lis;
        lis.push_back(a[lastInd]);
        while(hash[lastInd] != lastInd)
        {
            lastInd = hash[lastInd];
            lis.push_back(a[lastInd]);
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends