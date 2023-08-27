//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int minimumCost(int n,vector<vector<int>> &cars,int src,int dst,int k)
        {
            vector<int>distance(n,1e8);
            distance[src]=0;
            
            for(int i=0;i<=k;i++)
            {
               vector<int>temp;
               temp=distance;
               
               for(auto it:cars)
               {
                   int u=it[0];
                   int v=it[1];
                   int w=it[2];
                   
                   if(temp[v]> distance[u]+w)
                   {
                       temp[v]= distance[u]+w;
                   }
               }
               
               distance=temp;
               
               
            }
            if(distance[dst]==1e8) return -1;
            
            return distance[dst];
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,src,dst,k;
        cin>>n>>src>>dst>>k>>m;
        vector<vector<int>> cars(m,vector<int> (3));
        for(auto &j:cars)
            cin>>j[0]>>j[1]>>j[2];
        Solution s;
        cout<<s.minimumCost(n,cars,src,dst,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends