//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int getRSB(int k)
    {
        int count = 0;
        int x = 1;
        
        while(true)
        {
            count = count + 1;
            if(k&x) return count;
            else{
                x = x<<1;
            }
        }
    }
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int k = m^n;
        if(k==0) return -1;
        else{
            return getRSB(k);
        }
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends