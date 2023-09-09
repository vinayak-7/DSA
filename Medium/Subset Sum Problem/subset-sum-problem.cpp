//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // bool check(int ind , int sum , vector<int> &arr,vector<vector<int>> &dp)
    // {
    //     if(sum == 0) return true;
    //     if(ind == 0) return (arr[ind] == sum);
    //     if(dp[ind][sum] != -1) return dp[ind][sum];
        
    //     bool not_take = check(ind-1 , sum , arr,dp);
    //     bool take = false;
    //     if(sum >= arr[ind])
    //     {
    //         take = check(ind-1 , sum - arr[ind],arr,dp);
    //     }
        
    //     return dp[ind][sum] = take||not_take;
    // }
    bool isSubsetSum(vector<int>arr, int target){
        // code here 
        int index = arr.size();
        vector<vector<bool>> dp(index,vector<bool>(target+1,false));
        
        for(int i = 0 ; i < index ; i++)
        {
            dp[i][0] = true;
        }
        
        if(dp[0][arr[0]] <= target) dp[0][arr[0]] = true;
        
        for(int ind = 1 ; ind < index ; ind++)
        {
            for(int sum = 1 ; sum <= target ; sum++)
            {
                bool not_take = dp[ind-1][sum];
                bool take = false;
                
                if(arr[ind] <= sum)
                {
                    take = dp[ind-1][sum-arr[ind]];
                }
                
                dp[ind][sum] = take||not_take;
            }
        }
        return dp[index-1][target];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends