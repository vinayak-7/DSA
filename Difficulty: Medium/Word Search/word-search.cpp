//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& visited, string& word, int index) {
        if (index == word.size()) return true;  // If we matched the whole word
        
        int n = mat.size(), m = mat[0].size();
        
        // Out of bounds or already visited or character does not match
        if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || mat[row][col] != word[index]) {
            return false;
        }
        
        // Mark cell as visited
        visited[row][col] = 1;
        
        // Check all 4 possible directions
        int dRow[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
        int dCol[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            if (dfs(row + dRow[i], col + dCol[i], mat, visited, word, index + 1)) {
                return true;
            }
        }
        
        // Backtrack
        visited[row][col] = 0;
        return false;
    }

    bool isWordExist(vector<vector<char>>& mat, string word) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0)); // Initialize visited matrix
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) { // Start DFS from matching character
                    if (dfs(i, j, mat, visited, word, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends