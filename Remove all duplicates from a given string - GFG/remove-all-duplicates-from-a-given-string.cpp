//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    vector <int> vec(123,0);
	    string s= "";
	    
	    for(int i = 0 ; i < str.length() ; i++)
	    {
	        if(!vec[str[i]])
	        {
	            s += str[i];
	            vec[str[i]] = 1;
	        }
	    }
	    
	    return s;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends