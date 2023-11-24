//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<long long> ans;
        int mod = 1e9+7;
        vector<vector<long long>> vec(n,vector<long long>(n,0));
        vec[0][0] = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i-1==-1 or j-1==-1){
                    vec[i][j] = 1;
                }
                else{
                    vec[i][j] = (vec[i-1][j-1] + vec[i-1][j])%mod;
                }
            }
        }
        
        int k = n-1;
        for(int i=0;i<n;i++){
            ans.push_back(vec[k][i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends