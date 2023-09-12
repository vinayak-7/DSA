//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        string ans;
        if(s==0 && n>1) 
        return "-1";
        while(n>0)
        {
            if(s<9)
            {
              ans = ans+char(48+s);  
              s=0;
            }
            else
            {
                ans = ans+char(48+9);
                s=s-9;
            }
            --n;
        }
        if(s==0) return ans;
        else return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends