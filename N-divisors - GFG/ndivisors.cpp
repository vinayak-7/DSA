//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int cntDiv(int x)
    {
        int count = 0;
        int i = 1;
        for( ; i <= sqrt(x) ; i++)
        {
            if(i == sqrt(x)) count++;
            else if(x % i == 0) count += 2;
        }
        return count;
    }
    int count(int A,int B,int N){ 
        // code here
        int cnt = 0;
        for(int i = A ; i <= B ; i++)
        {
            if(cntDiv(i) == N) cnt++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,N;
        cin>>A>>B>>N;
        Solution ob;
        cout << ob.count(A,B,N) << endl;
    }
    return 0; 
}
// } Driver Code Ends