class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n ; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    ds.unionByRank(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(ds.findUPar(i) == i) cnt++;
        }
        
        return cnt;
    }
};