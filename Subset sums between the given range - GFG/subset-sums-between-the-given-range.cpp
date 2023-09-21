//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    long long int ways(int i,int n,int sum,vector<int>&arr,int cum)
    {
        
          if(i==n)
          {
              if(cum<=sum) return 1;
              return 0;
          }
          
           long long int a=ways(i+1,n,sum,arr,cum+arr[i]);
           long long int b=ways(i+1,n,sum,arr,cum);
           return a+b;
    }
    long long int countSubsets(vector<int>&arr, int n, int l, int r)
    {
          long long int x1=ways(0,n,r,arr,0);
          long long int x2=ways(0,n,l-1,arr,0);
         
          return x1-x2;
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
	    int l, r;
	    cin >> l >> r;
	    Solution ob;
	    long long int ans = ob.countSubsets(arr, n, l, r);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends