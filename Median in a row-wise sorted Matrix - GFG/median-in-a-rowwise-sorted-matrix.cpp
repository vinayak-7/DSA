//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here 
        // naive approach T.C:O(R*C(log(RC))) S.C: R*C
        // vector<int> ans;
        // for(int i = 0 ; i < R ; i++)
        // {
        //     for(int j = 0 ; j < C ; j++)
        //     {
        //       ans.push_back(matrix[i][j]); 
        //     }
        // }
        
        // sort(ans.begin(),ans.end());
        // int med = (((R*C)+1)/2)-1;
        
        // return ans[med];
        
        //optimized using binary search
        int minElement = matrix[0][0];
        int maxElement = matrix[0][C-1];
        
        for(int i = 0 ; i < R ; i++)
        {
            if(minElement > matrix[i][0]) minElement = matrix[i][0];
            if(maxElement < matrix[i][C-1]) maxElement = matrix[i][C-1];
        }
        
        int med = (R*C + 1)/2;
        while(minElement < maxElement)
        {
            int mid = minElement + (maxElement-minElement)/2;
            int place = 0;
            for(int i = 0 ; i < R ; i++)
            {
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(place < med) minElement = mid + 1;
            else maxElement = mid;
        }
        
        return minElement;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends