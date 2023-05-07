//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        long long q = 0 ; 
        long long divi = abs(dividend) ; long long dvisor = abs(divisor) ;
        for(int i = 31 ; i >= 0 ; i --){
            if((dvisor << i) <= divi){
                q = q + (1LL << i) ; 
                divi = divi - (dvisor << i) ; 
            }
        }
        if((dividend < 0 and divisor < 0) or (dividend > 0 and divisor > 0)) return q ; 
        
        return -1*q ;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends