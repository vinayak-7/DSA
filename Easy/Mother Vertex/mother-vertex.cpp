//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	void dfs(int vertex, vector<int> g[], vector<bool> &vis){
        vis[vertex] = true;
        for(auto child: g[vertex]){
            if (vis[child]) continue;
            dfs(child, g, vis);
        }
    }
	int findMotherVertex(int n, vector<int> g[])
	{
	    vector<bool> vis(n, false);
	    int ans=0;
	    for(int i=0; i<n; i++){
	        if (!vis[i]) {
	            dfs(i, g, vis); 
	            ans=i;
	        }
	    }
	    fill(vis.begin(), vis.end(), false);
	    dfs(ans, g, vis);
	    for(auto val: vis) if (!val) return -1;
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends