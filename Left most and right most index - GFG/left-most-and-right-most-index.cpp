//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> arr, long long k)
    {
        // code 
        int n = arr.size();
        int first = -1;
        int last = -1;
    
        int si = 0;
        int ei = n - 1;
    
        // To find first position
        while(si <= ei)
        {
            int mid = si + (ei - si) / 2;
    
            if(arr[mid] == k)
            {
                first = mid;
                ei = mid - 1;
            }
            else if(arr[mid] < k)
            {
                si = mid + 1;
            }
            else
            {
                ei = mid - 1;
            }
        }
    
        si = 0;
        ei = n - 1;
    
        // To find last position
        while(si <= ei)
        {
            int mid = si + (ei - si) / 2;
    
            if(arr[mid] == k)
            {
                last = mid;
                si = mid + 1;
            }
            else if(arr[mid] < k)
            {
                si = mid + 1;
            }
            else
            {
                ei = mid - 1;
            }
        }
    
        return make_pair(first, last);
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends