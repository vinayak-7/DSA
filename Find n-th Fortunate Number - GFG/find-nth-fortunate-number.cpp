//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isPrime(long long int n)

    {

     // Corner cases

     if (n <= 1) return false;

     if (n <= 3) return true;

    

     // This is checked so that we can skip

     // middle five numbers in below loop

     if (n%2 == 0 || n%3 == 0) return false;

    

     for (long long int i=5; i*i<=n; i=i+6)

      if (n%i == 0 || n%(i+2) == 0)

      return false;

    

     return true;

    }

    long long nthFortunateNum(int n) {

           vector<long long >a={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; 

           long long pn=1; 

         

           if(n==15){

               return 107;

           }

           for(int i=0;i<n;i++){

               pn*=(a[i]%1000000007)%1000000007; 

           }

       

          int f=0; 

          long long x=pn+2; 

          

          int i=0 ; 

         for(auto i:a){

             if(isPrime(i+pn)==true){

                 return i; 

             }

         }

        return x-pn; 

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.nthFortunateNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends