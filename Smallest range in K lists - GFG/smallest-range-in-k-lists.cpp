//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
          //code here
          priority_queue< pair<int,pair<int,int> >,
                        vector<pair<int,pair<int,int>> >,
                        greater<pair<int,pair<int,int>> > 
                        >pq;
            int mx=0;
            for(int i=0;i<k;i++){
              pq.push({a[i][0],{i,0}});
              mx=max(mx,a[i][0]);
          }
          int l=0,r=1e8;
          while(!pq.empty()){
              auto x=pq.top();
              if((r-l)>(mx-x.first)){
                  r=mx;
                  l=x.first;
              }
              
              pq.pop();
              if(x.second.second+1 >= n)    break;
              int val=a[x.second.first][x.second.second+1];
              mx=max(mx,val);
              pq.push({val,{x.second.first,x.second.second+1}});
              
          }
          return {l,r};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends