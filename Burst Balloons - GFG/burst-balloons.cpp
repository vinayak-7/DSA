//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int n, vector<int> &nums) {
        // code here
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>0;i--){
            for(int j=i;j<=n;j++){
                int maxCoins=INT_MIN;
                for(int k=i;k<=j;k++){
                    int coins=nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxCoins=max(maxCoins,coins);
                }

                dp[i][j]=maxCoins;
            }
        }
        return dp[1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends