//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int n = str.length();
        int x = 0;
        int y = 0;
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(str[i]== '0') x++;
            else y++;
            
            if(x==y) cnt++;
        }
        
        if( x != y) return -1;
        
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends