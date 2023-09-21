//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
  public:
    int rightmostNonZeroDigit(int n, int A[]){
        // code here 
        int x =1;
        int cnt2=0;
        int cnt5=0;
        for(int i=0; i<n; i++){
             if(A[i]==0)
              return -1;
            while(A[i]%2==0){
                cnt2++;
                A[i]/=2;
                
            }
            while(A[i]%5==0){
                cnt5++;
                A[i]/=5;
            }
            
            x=(x*A[i])%10;
        }
        int y= min(cnt2, cnt5);
        cnt2-=y;
        cnt5-=y;
        for(int i=0; i<cnt2; i++){
            x= (x*2)%10;
            
        }
        for(int i=0; i<cnt5; i++){
            x = (x*5)%10;
        }
        return x;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        Solution ob;
        cout << ob.rightmostNonZeroDigit(n, A) << endl;
    }
    return 0; 
} 
// } Driver Code Ends