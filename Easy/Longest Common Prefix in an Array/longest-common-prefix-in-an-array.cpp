//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        sort(arr,arr+n);
        string str = "" , first,last;
        first = arr[0];
        last = arr[n-1];
        int flag = 0;
        
        for(int i = 0 ; i <= min(first.size() ,last.size()) ; i++)
        {
            if(first[i] == last[i])
            {
                str += first[i];
                flag = 1;
            }
            
            else if(flag != 1) return "-1";
            
            else return str;
        }
        
        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends