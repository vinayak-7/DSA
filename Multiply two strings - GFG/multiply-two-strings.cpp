//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int n = s1.size();
       int m = s2.size();
       if (s1 == "0" || s2 == "0")return "0";
       vector<int> v(n+m, 0);
       for (int i=n-1; i>=0; i--)
       {
           for (int j=m-1; j>=0; j--)
           {
               if (s1[i] != '-' && s2[j] != '-')
               {
                    v[i+j+1] += (s1[i] - '0') * (s2[j] - '0');
                    v[i+j] += v[i+j+1]/10;
                    v[i+j+1] %= 10;
                    // Basic multiplication using maths 
                    // Try to dry run this for more clearation 
               }
           }
       }
        string ans;
        if (s1[0] == '-')ans = '-';
        else if (s2[0] == '-')ans = '-';
        // If leading of any string is '-' makes the answer also negative
        
        if (s1[0] == '-' && s2[0] == '-')ans = ""; 
        // leading '-' in s1 and '-' in s2 make answer '+'
        
        int i=0;
       while (i < n+m && v[i]==0)i++;
       // Ignoring leading zeros
       
       while (i < n+m)ans += to_string(v[i++]); 
       // converting vector of int in string
       
       return ans;
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends