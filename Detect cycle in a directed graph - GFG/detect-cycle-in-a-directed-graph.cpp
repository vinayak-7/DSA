//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool detect(int src,vector<int> adj[] , int vis[] , int pathVis[])
  {
      vis[src] = 1;
      pathVis[src] = 1;
      
      for(auto it: adj[src])
      {
          if(!vis[it])
          {
            //   cout<<it<<" ";
              if(detect(it,adj,vis,pathVis) == true) {
                return true;
              }
          }
          else if(pathVis[it]) {
            //   cout<<it<<" ";
              return true;
          }
      }
      pathVis[src] = 0;
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i = 0; i < V ; i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis,pathVis) == true) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends