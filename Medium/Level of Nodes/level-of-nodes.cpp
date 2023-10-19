//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	void dfs(int v,vector<int>adj[],int x,vector<int>&vis,int &ans,int lvl){
        vis[v]=1;
        if(v==x){
           ans=min(ans,lvl);
           return;
        }
        for(auto it:adj[v]){
            if(!vis[it]){
                dfs(it,adj,x,vis,ans,lvl+1);
            }
        }
    }
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	     vector<int>vis(V,0);
        int ans=1e8;
        dfs(0,adj,X,vis,ans,0);
        if(ans==1e8){
            return -1;
        }
        return ans;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends