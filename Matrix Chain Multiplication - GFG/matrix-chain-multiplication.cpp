//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMulti(int i , int j , int arr[] , int n,vector<vector<int>> &dp)
    {
        if(i == j) return 0;
        int mini = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k < j ; k++)
        {
            int steps = (arr[i-1]*arr[k]*arr[j]) + matrixMulti(i,k,arr,n,dp) + matrixMulti(k+1,j,arr,n,dp);
            mini = min(mini,steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return matrixMulti(1,n-1,arr,n,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends