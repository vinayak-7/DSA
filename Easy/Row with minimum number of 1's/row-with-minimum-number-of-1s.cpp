//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> arr) {
        // code here
        int mini = 1e9+7;
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int temp = 0;
            for(int j = 0 ; j < m ; j++)
            {
                if(arr[i][j] == 1) temp++;
            }
            if(temp < mini)
            {
                mini = temp;
                ans = i;
            }
        }
        
        return ans+1;
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
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends