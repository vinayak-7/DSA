//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int>st;
        queue<int>q;
        
        for(int i=0;i<N;i++) q.push(B[i]);
        
        for(int i=0;i<N;i++)
        {
            st.push(A[i]);
            while(st.empty()==false && q.empty()==false && st.top()==q.front() )
            {
                st.pop();
                q.pop();
            }
            
        }
        if(st.empty()) return 1;
        else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends