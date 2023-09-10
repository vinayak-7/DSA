//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(int ind , int sum , int arr[],vector<vector<int>> &dp)
    {
        if(sum == 0) return true;
        if(ind == 0) return (arr[ind] == sum);
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        bool not_take = check(ind-1 , sum , arr,dp);
        bool take = false;
        if(sum >= arr[ind])
        {
            take = check(ind-1 , sum - arr[ind],arr,dp);
        }
        
        return dp[ind][sum] = take||not_take;
    }
    int equalPartition(int ind, int arr[])
    {
        // code here
        int total_sum = 0;
        for(int i = 0 ; i < ind ; i++)
        {
            total_sum += arr[i];
        }
        if(total_sum % 2 != 0) return 0;
        
        int sum = total_sum/2;
        vector<vector<int>> dp(ind,vector<int>(sum+1,-1));

        return check(ind-1,sum,arr,dp);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends