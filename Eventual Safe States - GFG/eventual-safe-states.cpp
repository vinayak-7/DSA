//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  bool detect(int src,vector<int> adj[] , int vis[] , int pathVis[],int check[])
  {
      vis[src] = 1;
      pathVis[src] = 1;
      
      for(auto it: adj[src])
      {
          if(!vis[it])
          {
            //   cout<<it<<" ";
              if(detect(it,adj,vis,pathVis,check) == true) {
                return true;
              }
          }
          else if(pathVis[it]) {
            //   cout<<it<<" ";
              return true;
          }
      }
      check[src] = 1;
      pathVis[src] = 0;
      return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safenode;
        for(int i = 0; i < V ; i++)
        {
            if(!vis[i])
            {
                detect(i,adj,vis,pathVis,check);
            }
        }
        for(int i = 0 ; i < V ; i++)
        {
            if(check[i] == 1)
            {
                safenode.push_back(i);
            }
        }
        
        return safenode;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends