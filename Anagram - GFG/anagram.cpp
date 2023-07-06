//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(int i = 0 ; i < a.length() ; i++)
        {
            mp1[a[i]]++;
        }
        
        for(int i = 0 ; i < b.length() ; i++)
        {
            mp2[b[i]]++;
        }
        if(mp1.size() != mp2.size()) return false;
        for(int i = 0 ; i < mp1.size() ; i++)
        {
            if(mp1[a[i]] != mp2[a[i]]) return false;
        }
        
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends