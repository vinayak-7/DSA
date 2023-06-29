//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int odd = 0;
	    int even = 0;
	    
	    for(int i = 1; i <= s.size() ; i++)
	    {
	        if(i&1) odd = odd + (s[i-1]-'0');
	        else even = even + (s[i-1]-'0');
	    }
	    
	    return !((odd-even) % 3);
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends