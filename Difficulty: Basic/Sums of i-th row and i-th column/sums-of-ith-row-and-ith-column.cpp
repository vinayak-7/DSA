//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumOfRowCol(int n, int m, vector<vector<int>> mat) {
        // code here
        int x = min(n,m);
        
        for(int i = 0 ; i < x ; i++)
        {
            int sum1 = 0 ;
            int sum2 = 0 ;
            
            int j = 0;
            int k = 0;
            
            while(j < m)
            {
                sum1 += mat[i][j];
                j++;
            }
            while(k < n)
            {
                sum2 += mat[k][i];
                k++;
            }
            if(sum1 != sum2) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> A[i][j];
        Solution ob;
        cout << ob.sumOfRowCol(N, M, A) << "\n";
    }
}
// } Driver Code Ends