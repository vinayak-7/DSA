//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& heights, int n) {
        // Code here
        int prev = 0;
    int prev2 = 0;

    for(int ind = 1; ind < n ; ind++)
    {
        int jumpOne = prev + abs(heights[ind] - heights[ind-1]);
        int jumpTwo = INT_MAX;
        if(ind > 1)
            jumpTwo = prev2 + abs(heights[ind] - heights[ind-2]);
        prev2 = prev;
        prev = min(jumpOne,jumpTwo);
    }
    return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends