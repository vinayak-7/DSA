//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool isPrime(int x)
    {
        int a = sqrt(x);
        for(int i = 2 ; i <= a ; i++)
        {
            if(x % i == 0) return false;
        }
        
         return true;
    }
    long long int largestPrimeFactor(int n){
        // code here
        int a = sqrt(n);
        int maxi = 0;
        for(int i = 2 ; i <= a ; i++)
        {
            if(n % i == 0)
            {
                int c = n/i;
                if(isPrime(c)) maxi = max(maxi,c);
                else if(isPrime(i)) maxi = max(maxi,i);
            }
        }
        return maxi == 0 ? n : maxi;
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
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends