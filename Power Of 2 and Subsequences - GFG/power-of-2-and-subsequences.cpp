//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long long numberOfSubsequences(int N, long long input[]){
        // code here 
        long long sum = 0;
        long long value = 0;
        int mod = int(1e9 + 7);
        
        for(int i = 0 ; i < N ; i++)
        {
            int pos = log2(input[i]);
            if(((1<<pos)&input[i]) == input[i])
            {
                if(sum==0)
                {
                    value = 1;
                    sum = 1;
                }
                else
                {
                    sum = (sum + (value+1)%mod)%mod;
                    value = (value + (value+1)%mod)%mod;
                }
            }
        }
        
        return sum;
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
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
} 
// } Driver Code Ends