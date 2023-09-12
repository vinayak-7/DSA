//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int ind ,int len, int price[],vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            return ((int) (len * price[0]));
        }
        if(dp[ind][len] != -1) return dp[ind][len];
        int not_take = f(ind-1,len,price,dp);
        int take = INT_MIN;
        int rodLen = ind + 1;
        if(rodLen <= len)
        {
            take = price[ind] + f(ind,len - rodLen,price,dp);
        }
        
        return dp[ind][len] = max(take,not_take);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends