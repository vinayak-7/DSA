//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int solve(int i , int j,int isTrue,string &s,vector<vector<vector<int>>> &dp){
        
        if(i > j) return 0;
        if(i == j)
        {
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ways = 0;
        for(int k = i+1 ; k <= j-1 ; k += 2)
        {
            int leftTrue = solve(i ,k-1 ,1,s,dp);
            int leftFalse = solve(i ,k-1 ,0,s,dp);
            int rightTrue = solve(k+1 ,j ,1,s,dp);
            int rightFalse = solve(k+1 ,j ,0,s,dp);
            if(s[k] == '&' ) 
            {
                if(isTrue) ways =(ways % mod + (leftTrue * rightTrue) % mod) % mod;
                else ways += (leftTrue * rightFalse) % mod + (rightTrue * leftFalse) % mod + (leftFalse*rightFalse) % mod;
            }
            else if(s[k] == '^') 
            {
                if(isTrue) ways += (leftTrue * rightFalse) % mod + (rightTrue * leftFalse) % mod;
                else ways += (leftFalse*rightFalse) % mod + (leftTrue * rightTrue) % mod;
            }
            else
            {
                if(isTrue) ways = (ways % mod + (leftTrue*rightTrue) % mod 
                                    + (leftTrue*rightFalse) % mod + (leftFalse*rightTrue) % mod) % mod;
                else ways += (leftFalse*rightFalse) % mod;
            }
        }
        return dp[i][j][isTrue] = ways % mod;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(0,n-1,1,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends