//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    bool subsetSumUtil(int ind, int target, int arr[], vector<vector<int>> &dp) 
    {
        if (target == 0) return dp[ind][target]=true;
    
        if (ind == 0) return dp[ind][target] = arr[0] == target;
    
        if (dp[ind][target] != -1) return dp[ind][target];
    
        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
        bool taken = false;
        if (arr[ind] <= target)
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    
        return dp[ind][target] = notTaken || taken;
    }
	int minDifference(int arr[], int n)  
	{ 
	    // Your code goes here
	    int totSum = 0;

        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }
    
        vector < vector < int >> dp(n, vector < int > (totSum + 1, -1));
    
        for (int i = 0; i <= totSum; i++) 
        {
            subsetSumUtil(n - 1, i, arr, dp);
        }
        
        int mini = 1e9;
        for (int i = 0; i <= totSum; i++) 
        {
            if (dp[n - 1][i] == true) 
            {
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
      return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends