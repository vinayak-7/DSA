//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int cnt(int n)
    {
        int count = 0;
        while(n)
        {
            if(n&1) count++;
            n >>= 1;
        }
        return count;
    }
	int is_bleak(int n)
	{
	    // Code here.
	    
	    for(int i = n-1 ; i >= n - ceil(log2(n)) ; i--)
	    {
	        if(cnt(i) + i == n) return 0; 
	    }
	    
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends