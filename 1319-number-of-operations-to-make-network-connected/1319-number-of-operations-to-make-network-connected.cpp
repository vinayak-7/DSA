class Solution {
public:
    void bfs(vector<vector<int>>& adj,int curr, vector<bool>& vis ){
        queue<int>q;
        q.push(curr);
        vis[curr]=true;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            for(auto& node:adj[curr]){
                if(!vis[node]){ 
                    vis[node]=true;
                    q.push(node);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1; // if the number of connections is less than n-1 that means that we cannot connect all nodes reachable

        vector<bool>vis(n,false);
        vector<vector<int>>adj(n); // adjacency matrix
        for(auto& c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        int conn=-1;
        for(int i=0;i<n;++i){
            if(!vis[i]){ // if not visited, a connected component is present that is unvisited
                ++conn; 
                bfs(adj,i,vis);
            }
        }
        return conn;
    }
};