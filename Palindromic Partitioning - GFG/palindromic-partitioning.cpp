//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palin(string str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }

    int op(string str, int start, int end, vector<int>& dp) {
        if (start >= end) return 0;
        if (dp[start] != -1) return dp[start];

        int c = INT_MAX;
        for (int i = start; i < end; i++) {
            if (palin(str, start, i)) {
                c = min(c, 1 + op(str, i + 1, end, dp));
            }
        }

        if (palin(str, start, end - 1)) return 0;

        return dp[start] = c;
    }

    int palindromicPartition(string str) {
        vector<int> dp(str.size(), -1);
        return op(str, 0, str.size(), dp);
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