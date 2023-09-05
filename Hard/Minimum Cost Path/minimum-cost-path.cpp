//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
 
 
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>path(m,vector<int>(n,INT_MAX));
        path[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >q;
        q.push({grid[0][0],{0,0}});
        
        while(!q.empty()){
            int i=q.top().second.first;
            int j=q.top().second.second;
            int d=q.top().first;
            q.pop();
            if(i==m-1 && j==n-1) return d;
            for(int k=0;k<4;k++){
                int r=i+x[k];
                int c=j+y[k];
                if(r>=0 && r<m && c>=0 && c<n && path[r][c]>grid[r][c]+d){
                    
                    path[r][c]=grid[r][c]+d;
                    q.push({path[r][c],{r,c}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends