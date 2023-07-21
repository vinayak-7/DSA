//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,vector<int>> mp1,mp2;
        
        for( int i=0;i<2*e;i+=2){
            mp1[A[i]].push_back(A[i+1]);
        }
        for( int i=0;i<2*e;i+=2){
            mp2[B[i]].push_back(B[i+1]);
        }
        
        for( int i=1;i<n+1;i++){
            reverse(mp2[i].begin(),mp2[i].end());
            if(mp1[i]!=mp2[i])  return false; 
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends