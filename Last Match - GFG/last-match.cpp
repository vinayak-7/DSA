//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string A,string B){
        //Code Here
        int n = A.size();
        int m = B.size();
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        
        int t = A.find(B);
        
        return t == -1 ? -1 : n - t - m + 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends