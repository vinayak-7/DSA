//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        //code here.
        unordered_map <int,int> m;
        vector <int> ans;
        for(int i = 0;i < k;i++) m[a[i]]++;
        for(int i = 0;i < n-k;i++){
            ans.push_back(m.size());
            if(m[a[i]]-- == 1) m.erase(a[i]);
            m[a[i+k]]++;
        }
        ans.push_back(m.size());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends