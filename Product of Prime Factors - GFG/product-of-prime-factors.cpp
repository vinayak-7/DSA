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
    long long int primeProduct(int n){
        //code here
        long long int prod = 1;
        for(int i = 1 ; i <= sqrt(n) ; i++)
        {
            if(n % i == 0)
            {
                int c = n / i;
                if(isPrime(c) && c != i){
                    prod = prod * c;
                }
                if(isPrime(i)) 
                {
                    prod = prod * i;
                }
            }
        }
        
        return prod;
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
        cout << ob.primeProduct(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends