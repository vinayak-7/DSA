//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<int> dp(w+1 , 0);
        
        for(int i = 0 ; i <= w; i++) dp[i] = (val[0]*(i/wt[0])) ;
        
        for(int i = 1 ; i < n ; i++)
        {
            vector<int> temp(w+1 , 0);
            for(int j = 0 ; j <= w; j++)
            {
                int included = wt[i] <= j ? val[i] + temp[j-wt[i]] : 0;
                int notIncluded = dp[j];
                
                temp[j] = max(included,notIncluded);
            }
            dp = temp;
        }
        return dp[w];
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