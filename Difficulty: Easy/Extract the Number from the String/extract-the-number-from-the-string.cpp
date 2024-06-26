//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string str) {

        // code here
        long long ans = -1;
        
        for(int i = 0 ; i < str.size() ; i++)
        {
            
            if(str[i] >= '0' && str[i] <= '9')
            {
                long long temp = 0;
                
                while(str[i] >= '0' && str[i] <= '8')
                {
                    temp = (long long)temp*10 + (str[i]-'0');
                    i++;
                }
                if(str[i] == '9')
                {
                    temp = -1;
                    while(str[i] >= '0' && str[i] <= '9') i++;
                }
                ans = max(ans,temp);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends