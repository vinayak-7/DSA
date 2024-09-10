//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Helper function to check if all vertices with non-zero degree are connected
bool isConnected(vector<vector<int>>& adj, vector<int>& in_degree, vector<int>& out_degree) {
    vector<bool> visited(26, false);
    
    // Find the first vertex with a non-zero out-degree
    int start_node = -1;
    for (int i = 0; i < 26; ++i) {
        if (out_degree[i] > 0) {
            start_node = i;
            break;
        }
    }
    
    // Perform DFS from this start node
    if (start_node == -1) {
        return true; // If there are no edges, the graph is trivially connected
    }
    
    dfs(start_node, adj, visited);
    
    // Check if all vertices with non-zero in-degree or out-degree were visited
    for (int i = 0; i < 26; ++i) {
        if ((in_degree[i] > 0 || out_degree[i] > 0) && !visited[i]) {
            return false;
        }
    }
    
    return true;
}
    int isCircle(vector<string> &arr) {
        // code here
        vector<vector<int>> adj(26);  // Adjacency list for the directed graph
        vector<int> in_degree(26, 0), out_degree(26, 0);
        
        // Build the graph from the strings
        for (const string& str : arr) {
            int u = str.front() - 'a';  // First character
            int v = str.back() - 'a';   // Last character
            adj[u].push_back(v);
            out_degree[u]++;
            in_degree[v]++;
        }
        
        // Check condition 1: Each vertex must have equal in-degree and out-degree
        for (int i = 0; i < 26; ++i) {
            if (in_degree[i] != out_degree[i]) {
                return false;
            }
        }
        
        // Check condition 2: The graph must be strongly connected
        return isConnected(adj, in_degree, out_degree);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends