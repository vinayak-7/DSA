//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class triplet{
    public:
    int r ;
    int c;
    int time;
    
    triplet(int r, int c, int time)
    {
        this -> r = r;
        this -> c = c;
        this -> time = time;
    }
};
class Solution 
{
    private:
    vector<vector<int>> bfs(vector<vector<int>> &vis,vector<vector<int>> &grid,int n,int m)
    {
        queue<triplet> q;
        int time = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push(triplet(i,j,0));
                    vis[i][j] = 1;
                    grid[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            triplet t = q.front();
            q.pop();
            
            int r = t.r;
            int c = t.c;
            int tm = t.time;
            
            time = max(tm,time);
            
            for(int it = -1 ; it <= 1 ; it += 2)
            {
                if( r + it >= 0 && r + it < n && !vis[r + it][c] && grid[r + it][c] == 0)
                {
                    vis[r + it][c] = 1;
                    q.push(triplet(r+it,c,time+1));
                    grid[r + it][c] = time+1;
                    
                }
                if( c + it >= 0 && c + it < m && !vis[r][c+it] && grid[r][c+it] == 0)
                {
                    vis[r][c + it] = 1;
                    q.push(triplet(r,c + it,time+1));
                    grid[r][c + it] = time+1;
                    
                }
            }
        }
        return grid;
    }
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        bfs(vis,grid,n,m);
        
        return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends