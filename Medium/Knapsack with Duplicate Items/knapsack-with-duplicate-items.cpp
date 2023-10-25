//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int ind , int w , int wt[], int val[],vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            return ((int) w /wt[0]) * val[0];
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int not_take = f(ind-1,w,wt,val,dp);
        int take = INT_MIN;
        if(wt[ind] <= w)
        {
            take = val[ind] + f(ind,w-wt[ind],wt,val,dp);
        }
        
        return dp[ind][w] = max(take,not_take);
    }
    int knapSack(int n, int maxWt, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(maxWt+1,-1));
        return f(n-1,maxWt,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends