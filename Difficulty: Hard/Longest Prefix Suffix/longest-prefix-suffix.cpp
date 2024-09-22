//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int count = 0;
        int i = 0 ;
        int j = 1 ;
        int k = 1 ;
        while(i < str.size() && j < str.size())
        {
            if(str[i] == str[j])
            {
                count++;
                i++;
                j++;
            }
            else{
                j=k;
                k++;
                i = 0;
                count = 0;
            }
            
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends