//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.size();
		    vector<string> subs;
		    for(int i = 1 ; i < (1<<n) ; i++){
		        string sub;
		        for(int j = 0 ; j < n; j++)
		        {
		            if(i&(1<<j))
		            {
		                sub += s[j];
		            }
		        }
		        subs.push_back(sub);
		    }
		    sort(subs.begin(),subs.end());
		    
		    return subs;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends