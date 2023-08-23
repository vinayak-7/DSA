//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    // kosaraju algorithms
    
    private:
    
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int> adj[], vector<int> &vis, vector<int>&ds) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs2(it, adj, vis, ds);
            }
        }
        ds.push_back(node);
    }
    
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<vector<int>> scc;
        vector<int> ds, vis1(V, 0), vis2(V, 0);
        stack<int> st;
        
        vector<int> adj2[V];
        
        for(int i = 0 ; i < V ; i++) {
            if(!vis1[i]) {
                dfs(i, adj, vis1, st);
            }
        }
        
        for(int i = 0 ; i < V ; i++) {
            for(auto it : adj[i]) {
                adj2[it].push_back(i);
            }
        }
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis2[node]) {
                dfs2(node, adj2, vis2, ds);
                sort(ds.begin(), ds.end());
                scc.push_back(ds);
                ds.clear();
            }
        }
        
        sort(scc.begin(), scc.end());
        
        
        return scc;
        
    }
};
//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends