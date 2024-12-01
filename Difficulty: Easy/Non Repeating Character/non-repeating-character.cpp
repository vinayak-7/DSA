//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        unordered_map<char , int> mp;
       
       for(int i = 0 ; i < s.size() ; i++)
       {
           char ch = s[i];
           mp[ch]++;
       }
       
       for(int i = 0 ; i < s.size() ; i++)
       {
           char ch = s[i];
           if(mp[ch] == 1)
           {
               return ch;
           }
       }

       return '$';
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends