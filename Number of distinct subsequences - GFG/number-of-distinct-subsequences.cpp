//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function template for C++

class Solution{
  public:
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


   
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends