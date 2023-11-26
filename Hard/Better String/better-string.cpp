//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        int distinctSubsequences(string str)
    	{
    		vector<int> last(26, -1); 
    
    		int mod = 1e9 + 7;
    	    int n = str.size(); 
    	    long long dp[n + 1]; 
    	  
    	    // Empty substring has only one subsequence 
    	    dp[0] = 1; 
    	  
    	    // Traverse through all lengths from 1 to n. 
    	    for (int i = 1; i <= n; i++) { 
    	        
    	        dp[i] = 2 * dp[i - 1]; 
    	        dp[i] %= mod;
    	        if (last[str[i - 1] - 'a'] != -1) 
    	            dp[i] = (dp[i] - dp[last[str[i - 1] - 'a']] + mod)%mod; 
    	  
    	        // Mark occurrence of current character 
    	        last[str[i - 1] - 'a'] = (i - 1); 
    	    } 
    	  
    	    return (int)(dp[n]);
    	}
    public:
        string betterString(string str1, string str2) {
            // code here
            int n = distinctSubsequences(str1);
            int m = distinctSubsequences(str2);
            if(m > n) return str2;
            return str1;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends