//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        int count = 0;
        int m = 1;
        
        int temp = 0;
        for(int i = 0 ; i < 32 ; i++)
        {
            int a = N & m;
            if(a==1)
            {
                count++;
                temp = i+1;
            }
            N = N >> 1;
        }
        
        if(count != 1) return -1;
        else return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends