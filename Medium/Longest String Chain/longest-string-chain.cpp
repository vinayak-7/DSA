//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(string &s1 , string &s2)
    {
        if(s1.size() != s2.size()+1) return false;
        int first = 0;
        int second = 0;
        while(first < s1.size())
        {
            if(s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    static bool comp(string &s1 , string &s2)
    {
        return s1.size() < s2.size();
    }
    int longestChain(int n, vector<string>& words) {
        // Code here
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int len = 1;
        for(int ind = 0 ; ind < n ; ind++)
        {
           for(int prev = 0 ; prev < ind ; prev++)
           {
               if(check(words[ind] , words[prev]) && 1 + dp[prev] > dp[ind] )
               {
                   dp[ind] = 1 + dp[prev];
               }
           }
           len = max(len,dp[ind]);
        }
        return len;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends