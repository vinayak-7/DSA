//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	int mask_1 = 0xAAAAAAAA; // every even bit is 1

        int mask_2 = 0x55555555; // every odd bit is 1

        int even_part = (n & mask_1);

        int odd_part = (n & mask_2);

        even_part = even_part>>1;

        odd_part = odd_part<<1;

        return (even_part|odd_part);
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends