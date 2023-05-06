//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long game(long long int n,vector<int> &opt , int i,vector<vector<int>> &dp)
{
    if(n==0) return 1;
    if(i < 0) return n == 0;
    
    if(dp[i][n] != -1) return dp[i][n];
    
    long long move = n - opt[i] >= 0 ? game(n-opt[i],opt,i,dp): 0;
    long long dontMove = game(n,opt,i-1,dp);
    
    return dp[i][n] = move + dontMove;
}
long long int count(long long int n)
{
	vector<int> opt{3,5,10};
	vector<vector<int>> dp(3 , vector<int>(n+1,-1));
	return game(n,opt,2,dp);
	
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends