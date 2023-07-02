//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required

    vector<vector<int> > fourSum(vector<int> &arr, int sum) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int> > ans;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                int left = j+1;
                int right = n-1;
                while(left < right)
                {
                    if(arr[i] + arr[j] + arr[left] + arr[right] == sum)
                    {
                        ans.push_back({arr[i],arr[j],arr[left],arr[right]});
                    }
                    if(arr[i] + arr[j] + arr[left] + arr[right] < sum) left++;
                    else right--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends