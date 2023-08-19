//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
{
    long long dp[n];
    
    //continous sum lo ya fir khud se start kro 
    //max sum lena h 
    for(int i =0;i<n;i++)
    {
        dp[i] = (i==0)?arr[i]:(max(arr[i] , dp[i-1] +arr[i]));
    }
    
    // dp -meaning - > iss index tkk m max kitna sum bnn skta h starting se ya akele hi
    //window fix krrdo k size ka abb window ka sum lo aur window k pehle k dp ka bhi add krr 
    //ke dekho maxsum bnna chahiye
    long long sum = 0;
    sum = accumulate(arr ,arr +k , 0);
    long long ans = INT_MIN;
    ans = max(ans , sum);
    
    //slide window
    for(int i = k;i<n;i++)
    {
        sum = sum +arr[i] - arr[i-k];
        ans = max(sum , ans);
        ans =max(ans , dp[i-k] +sum);
    }
    
    return ans;
}