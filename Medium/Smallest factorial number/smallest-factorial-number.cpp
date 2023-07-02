//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int solve(int n)
        {
            int ans=0;
            while(n>0){
                ans+=n/5;
                n/=5;
            }
            return ans;
        }
        int findNum(int n){
            int lo=1;
            int hi=n*5;
            int ans;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(solve(mid)>=n){
                    hi=mid-1;
                    ans=mid;
                }
                else lo=mid+1;
            }
            return ans;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends