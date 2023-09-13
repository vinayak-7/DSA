//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void allLCSUtil(string s,string t,vector<vector<int>>& dp,set<string>& ans,int x,int y,string lcs,int len){
	        if(lcs.length()==len){
	            reverse(lcs.begin(),lcs.end()) ;
	            ans.insert(lcs) ; 
	            return ;
	        }
	        for(int i=x ; i>0 ; i--){
	            for(int j=y ; j>0 ; j--){
	                if(s[i-1]==t[j-1])  allLCSUtil(s,t,dp,ans,i-1,j-1,lcs+s[i-1],len) ; 
	            }
	        }
	    }

		vector<string> all_longest_common_subsequences(string s1, string s2)
		{
		    // Code here
		    int n = s1.size();
		    int m = s2.size();
		    
		    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
            for(int i = 0 ; i <= n ; i++)
            {
                dp[i][0] = 0;
            }
            for(int j = 0 ; j <= m ; j++)
            {
                dp[0][j] = 0;
            }
            
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                    else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
            
            set<string> ans ; 
		    allLCSUtil(s1,s2,dp,ans,n,m,"",dp[n][m]) ; 
		    vector<string> result ; 
		    
		    for(auto i : ans)   result.push_back(i) ; 
		    
            return result ;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends