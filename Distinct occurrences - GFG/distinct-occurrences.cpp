//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    int mod = 1e9+7;
    public:
    int count(int i , int j , string& s1 , string& s2,vector<vector<int>> &dp)
    {
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j])
        {
            return dp[i][j] = (count(i-1,j-1,s1,s2,dp)%mod + count(i-1,j,s1,s2,dp)%mod)%mod;
        }
        else return dp[i][j] = count(i-1,j,s1,s2,dp)%mod;
    }
    int subsequenceCount(string s1, string s2)
    {
      //Your code here
      int n = s1.size();
      int m = s2.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return count(n,m,s1,s2,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends