//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int f(int i, int j ,string s1, string s2, vector<vector<int>>&dp){
        if(i<0 && j<0) return 1;
        if(i<0 && j>=0) return 0;
        if(i>=0 && j<0){
            for(int p=0; p<=i; p++){
                if(s1[p]!='*') return 0;
            }return 1;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j] || s1[i]=='?'){
            return dp[i][j]=f(i-1, j-1, s1, s2, dp);
        }
        if(s1[i]=='*'){
            return dp[i][j]=(f(i-1, j, s1, s2, dp) || f(i, j-1, s1, s2, dp));
        }
    }
    int wildCard(string pattern,string str)
    {
        int x=pattern.size();
        int y=str.size();
        vector<vector<int>>dp(x, vector<int>(y, -1));
        return f(x-1, y-1, pattern, str, dp);
    }

};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends