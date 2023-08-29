//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
         vector<vector<int>> p(N,vector<int>(3,-1));
      vector<int> ans;
      for(int i=0;i<S.size();i++){
          p[i][0]=F[i];
          p[i][1]=S[i];
          p[i][2]=i;
      }
      sort(p.begin(),p.end());
      ans.push_back(p[0][2]+1);
      int current=p[0][0];
      
      for(int i=1;i<p.size();i++){
          if(current<p[i][1]){
              ans.push_back(p[i][2]+1);
              current=p[i][0];
          }
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends