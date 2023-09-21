//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int counter = 0;

    void dfs(vector<vector<int>>& graph, int root, int parent, int entryTime[], int exitTime[]) {
        counter++;
        entryTime[root] = counter;
        
        for (auto node : graph[root]) {
            if (node != parent) {
                dfs(graph, node, root, entryTime, exitTime);
            }
        }
        
        exitTime[root] = counter;
    }

    bool checkIfIsInSubtree(int a, int b, int entryTime[], int exitTime[]) {
        return (entryTime[a] <= entryTime[b] && exitTime[a] >= exitTime[b]);
    }

    vector<string> isInSubtree(vector<vector<int>>& graph, int n, int q, vector<vector<int>>& queries) {
        int entryTime[n + 1], exitTime[n + 1];
        dfs(graph, 1, -1, entryTime, exitTime);
        
        vector<string> result;
        
        for (auto query : queries) {
            if (checkIfIsInSubtree(query[1], query[0], entryTime, exitTime))
                result.push_back("YES");
            else
                result.push_back("NO");
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> g(n+1);
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int q;
        cin>>q;
        vector <vector<int>> queries(q,vector<int> (2));
        for(auto &j:queries)
            cin>>j[0]>>j[1];
        
        Solution s;
        vector<string> ans=s.isInSubtree(g,n,q,queries);
        for(auto j:ans)
            cout<<j<<endl;
    }
    return 0;
}
// } Driver Code Ends