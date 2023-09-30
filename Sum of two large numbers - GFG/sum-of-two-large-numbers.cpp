//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string x, string y) {
        string ans ="";
        int n,m; 
        n = x.size(), m = y.size();
        int i,j, dig, carry = 0;
        for( i = n-1, j = m -1; i >= 0 || j >=0 ; i--, j--) {
             dig = (i>=0?x[i]-'0':0) + (j>=0?y[j]-'0':0) + carry;
            ans.push_back('0'+ (dig%10));
            carry = dig/10;
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        
        //removing leading zeroes
        n = ans.size();
        for(i = 0; i < n && ans[i]=='0'; i++); // i has last index of leading zeroes
        ans = i==n?"0":ans.substr(i, n - i); // removing leading zeroes. if all are zeroes then ans ='0'
        
        return ans;
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
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends