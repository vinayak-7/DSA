//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int a[]){
        //Write your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({a[i],i+1});
        }
        sort(v.begin(),v.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(v[i].first*v[i].second<=k)
            {
                count+=v[i].second;
                k-=v[i].first*v[i].second;
                
            }
            else
            {
                int c=k/v[i].first;
                count+=c;
                k-=c*v[i].first;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends