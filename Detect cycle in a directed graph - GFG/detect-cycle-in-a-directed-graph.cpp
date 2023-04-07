//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
//   private:
//   bool detect(int src,vector<int> adj[] , int vis[] , int pathVis[])
//   {
//       vis[src] = 1;
//       pathVis[src] = 1;
      
//       for(auto it: adj[src])
//       {
//           if(!vis[it])
//           {
//             //   cout<<it<<" ";
//               if(detect(it,adj,vis,pathVis) == true) {
//                 return true;
//               }
//           }
//           else if(pathVis[it]) {
//             //   cout<<it<<" ";
//               return true;
//           }
//       }
//       pathVis[src] = 0;
//       return false;
//   }
//   public:
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<int> adj[]) {
//         // code here
//         int vis[V] = {0};
//         int pathVis[V] = {0};
        
//         for(int i = 0; i < V ; i++)
//         {
//             if(!vis[i])
//             {
//                 if(detect(i,adj,vis,pathVis) == true) return true;
//             }
//         }
        
//         return false;
//     }
public:
bool isCyclic(int V, vector<int> adj[])
{
    int inDegree[V] = {0};
        
        for(int i = 0; i < V ; i++)
        {
            for(auto it: adj[i])
            {
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0 ; i < V ; i++)
        {
            if(inDegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            // node is in your topo sort
            // so please remove it from indegree
            for(auto it: adj[node])
            {
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(cnt == V) return false;
        return true;
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