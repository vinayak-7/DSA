//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        long long mod=1e9+7;
        long long dp[n+1];
        dp[0]=1;
        for(long long i=1; i<=n; i++)
        {
            dp[i]=0;
            for(long long j=0; j<i; j++)
            {
                dp[i]=(dp[i]+(dp[j]*dp[i-j-1])%mod)%mod;
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends