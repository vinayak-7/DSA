//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int getTillN(int n){
        int x = 1;
        int power = 0;
        
        while(x*2 <= n)
        {
            power = power +1;
            x = x*2;
        }
        
        return power;
    }
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0) return 0;
        int p = getTillN(n);
        
        return ((1<<p-1)*p) + 1 + (n-(1<<p))+ countSetBits(n-(1<<p));
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends