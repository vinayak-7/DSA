//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        if(n==1) return "1";
        // recursion
        string s = lookandsay(n-1);
        string res = "";
        int cntr = 0;
        
        
        for(int j = 0; j < s.length() ; j++){
            cntr++;
            // segregating into groups
            if(j == s.length() - 1 || s[j] != s[j+1])
            {
                res = res +to_string(cntr)+ s[j];
                cntr = 0;
            }
        }
        return res;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends