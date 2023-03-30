//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(vector<vector<int>>& image,vector<vector<int>> &vis,int row ,int col , int newColor , int oldColor)
    {
        int n = image.size();
        int m = image[0].size();
        vis[row][col] = 1;
        
        image[row][col] = newColor;
        
        for(int i = -1 ; i <= 1 ; i += 2)
        {
            if( row - i >= 0 && row - i < n && !vis[row-i][col] && image[row-i][col] == oldColor)
            {
                dfs(image,vis,row-i,col,newColor,oldColor);
            }
            if( col - i >= 0 && col - i < m && !vis[row][col-i] && image[row][col-i] == oldColor)
            {
                dfs(image,vis,row,col-i,newColor,oldColor);
            }
        }
    }
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            // Code here 
            
            int oldColor = image[sr][sc];
            int n = image.size();
            int m = image[0].size();
            vector<vector<int>> vis(n,vector<int>(m,0));
            if(oldColor == newColor) return image;
            if(!vis[sr][sc])
                {
                    dfs(image,vis,sr,sc,newColor,oldColor);
                }
            
            return image;
            
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends