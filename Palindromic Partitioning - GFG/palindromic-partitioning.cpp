//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPalindrome(string str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }

    // int f(string str, int start, int end, vector<int>& dp) {
    //     if (start == end) return 0;
    //     if (dp[start] != -1) return dp[start];

    //     int minCost = INT_MAX;
    //     for (int i = start; i < end; i++) {
    //         if (isPalindrome(str, start, i)) {
    //             minCost = min(minCost, 1 + f(str, i + 1, end, dp));
    //         }
    //     }
    //     return dp[start] = minCost;
    // }

    int palindromicPartition(string str) {
        int n = str.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        
        for(int start = n-1 ; start >= 0 ; start--)
        {
            //start....i
            int minCost = INT_MAX;
            for (int i = start; i < n; i++) {
                if (isPalindrome(str, start, i)) {
                    minCost = min(minCost, 1 + dp[i+1]);
                }
            }
            dp[start] = minCost;
        }
        return dp[0]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends