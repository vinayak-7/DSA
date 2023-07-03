//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    int setBits(int N) {
        int res = 0;
        while(N>0)
        {
            N = N & (N-1);
            res++;
        }

        return res;
    }
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
       return a.second > b.second;
    }
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<pair<int,int>> ans;
        for(int i = 0 ; i < n ; i++)
        {
            int count = setBits(arr[i]);
            ans.push_back({arr[i],count});
        }
        
        stable_sort(ans.begin(),ans.end(),cmp);
        for(int i = 0 ; i < n ; i++)
        {
            arr[i] = ans[i].first;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends