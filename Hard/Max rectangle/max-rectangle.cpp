//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    private:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0){
            return 0;
        }
        vector<int>left(n);
        vector<int>right(n);
        int area=0;
        left[0]=-1;
        right[n-1]=n;
        // for left
        for(int i=1;i<n;i++){
            int previous=i-1;
            while(previous>=0 && heights[previous]>=heights[i]){
                previous=left[previous];
            }
            left[i]=previous;
        }
        // for right 
        for(int i=n-2;i>=0;i--){
            int forward=i+1;
            while(forward<n && heights[forward]>=heights[i]){
                forward=right[forward];
            }
            right[i]=forward;
        }
        // area
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int area1=heights[i]*width;
            if(area1>area){
                area=area1;
            }
        }
        return area;   
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>v(m);
        for(int i=0;i<m;i++){
            v[i]=0;
        }
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0){
                    v[j]=v[j]+M[i][j];
                }
                else{
                    v[j]=0;
                }
            }
            int area1=largestRectangleArea(v);
            if(area1>area){
                area=area1;
            }
        }
        return area;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends