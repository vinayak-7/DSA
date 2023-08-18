//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int count(int N)
    {
         // Base cases (Assuming N is not negative)  
        if (N < 3)  
            return N;  
        if (N >= 3 && N < 10)  
            return N-1;  
      
        // Calculate 10^(d-1) (10 raise to the power d-1) where d is  
        // number of digits in N. po will be 100 for N = 578  
        int po = 1;  
        while (N/po > 9)  
            po = po*10;  
      
        // find the most significant digit (msd is 5 for 578)  
        int msd = N/po;  
      
        if (msd != 3)  
            // For 578, total will be 4*count(10^2 - 1) + 4 + count(78)  
            return count(msd)*count(po - 1) + count(msd) + count(N%po);  
        else
            // For 35, total will be equal to count(29)  
            return count(msd*po - 1);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends