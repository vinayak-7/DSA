//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void help(string s,vector<string>&ans,int i=0)
    {
        if(s.length()-1==i)
        {
            ans.push_back(s);
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            swap(s[i],s[j]);
            help(s,ans,i+1);
            swap(s[i],s[j]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
         vector<string>ans;
         help(S,ans);
         sort(ans.begin(),ans.end());
         return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends