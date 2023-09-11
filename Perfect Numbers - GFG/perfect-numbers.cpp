//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N==1)return 0; //handle this case explicitly.
        long long i;
        long long ans =1;
        //we will run the loop till square root of N, and store the value of i, in            //same line we will also store the correspoding divisor. i.e- N/i.
        for(i=2;i*i<=N; i++){
            if(N%i==0)ans+=i + (N/i);
        }
        // cout<<ans;
        return ans==N?1:0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends