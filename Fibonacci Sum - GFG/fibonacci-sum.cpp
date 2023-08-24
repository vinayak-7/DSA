//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int n){
        //code here
        long long int mod = 1000000007;
        long long int prev2 = 0;
        long long int prev = 1;
        long long int sum = 1;
        
        for(long long int i = 2 ; i <= n ; i++)
        {
            long long int curr = (prev + prev2)%mod;
            prev2 = prev%mod;
            prev = curr%mod;
            sum = (sum + curr)%mod; 
        }
        
        return sum % 1000000007;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends