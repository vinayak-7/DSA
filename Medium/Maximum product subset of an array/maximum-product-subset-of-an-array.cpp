//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here 
        if(n == 1) return a[0];
        long long int ans = 1,mod = 1e9 + 7;
        int mx = -11,c = 0,z = 0;
        for(int i = 0;i < n;i++){
            if(a[i] < 0){
                c++;
                mx = max(mx,a[i]);
            }
            if(a[i]) ans = (ans*a[i])%mod;
            else z++;
        }
        if(c == 1 && z == n-1 || z == n) return 0;
        return c%2 ? ans/mx : ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends