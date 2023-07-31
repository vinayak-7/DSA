//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        unordered_map<char,int> mp;
        for(auto it: str) mp[it]++;
        
        int i = 0;
        int j = 0;
        int n = str.length();
        unordered_map<char,int> mp2;
        int minm = 1e9;
        
        while(j < n)
        {
            mp2[str[j]]++;
            while(i < n && mp2.size() == mp.size())
            {
                mp2[str[i]]--;
                if(mp2[str[i]] == 0) mp2.erase(str[i]);
                
                minm = min(j-i+1,minm);
                i++;
            }
            j++;
        }
        
        return minm;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends