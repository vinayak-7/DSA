//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string str) {
        // code here
        int n = str.size(); // calculating size of string
        if (n < 2)
            return str; // if string is empty then size will be 0.
                      // if n==1 then, answer will be 1(single
                      // character will always palindrome)
     
        int maxLength = 1, start = 0;
        int low, high;
        for (int i = 0; i < n; i++) {
            low = i - 1;
            high = i + 1;
            while (high < n
                   && str[high] == str[i]) // increment 'high'
                high++;
     
            while (low >= 0
                   && str[low] == str[i]) // decrement 'low'
                low--;
     
            while (low >= 0 && high < n
                   && str[low] == str[high]) {
                low--;
                high++;
            }
     
            int length = high - low - 1;
            if (maxLength < length) {
                maxLength = length;
                start = low + 1;
            }
        }
        
        return str.substr(start, maxLength);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends