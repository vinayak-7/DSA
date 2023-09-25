//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(), A.end(),greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        priority_queue<pair<int, pair<int,int>>> p;
        for(int i = 0; i < N; i++) p.push({A[i] + B[0], {i, 0}});
        vector<int> ans;
        while(K)
        {
            ans.push_back(p.top().first);
            int x = p.top().second.first;
            int y = p.top().second.second;
            p.pop();
            p.push({A[x] + B[y+1], {x, y+1}});
            K--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends