//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int> dp1(n,1),dp2(n,1);
        int len = 1;
        for(int ind = 0 ; ind < n ; ind++)
        {
           for(int prev = 0 ; prev < ind ; prev++)
           {
               if(nums[prev] < nums[ind])
               {
                   dp1[ind] = max(dp1[ind] , 1 + dp1[prev]);
               }
           }
        }
        
        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
           for(int prev = n-1 ; prev > ind ; prev--)
           {
               if(nums[prev] < nums[ind])
               {
                   dp2[ind] = max(dp2[ind] , 1 + dp2[prev]);
               }
           }
           len = max(len , dp1[ind] + dp2[ind] - 1);
        }
        return len;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends