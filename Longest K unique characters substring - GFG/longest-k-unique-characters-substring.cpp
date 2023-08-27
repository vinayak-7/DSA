//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int ans = -1;
        int n = s.size();
        
        unordered_map<char,int>m;
        for (int i = 0; i<k; i++){
            m[s[i]]++;
        }
        
        if (m.size()==k) ans = k;
        
        int l = 0;
        for (int i = k; i<n; i++){
            m[s[i]]++;
            int x = m.size();
            if (x == k){
                ans = max(ans,i-l+1);
            }
            if (x>k){
                while(true){
                    m[s[l]]--;
                    if (m[s[l]] == 0){
                        m.erase(s[l]);
                    }
                    l++;
                    if (m.size()==k) break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends