//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long a[], int n)
    {
        stack<pair<long long ,long long>> s;
        vector<long long> r;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                r.push_back(n);
            }
            else
            {
                if((s.top()).first<a[i])
                {
                    r.push_back((s.top()).second);
                }
                else
                {
                    while(s.size()>0&&(s.top()).first>=a[i])
                    {
                        s.pop();
                    }
                    if(s.empty())
                    {
                        r.push_back(n);
                    }
                    else
                    {
                        r.push_back((s.top()).second);
                    }
                }
            }
            s.push({a[i],i});
        }
        reverse(r.begin(),r.end());
        //finding smaller element to left
        while(!s.empty())
        {
            s.pop();
        }
        vector<long long> l;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                l.push_back(-1);
            }
            else
            {
                if((s.top()).first<a[i])
                {
                    l.push_back((s.top()).second);
                }
                else
                {
                    while(s.size()>0&&(s.top()).first>=a[i])
                    {
                        s.pop();
                    }
                    if(s.empty())
                    {
                        l.push_back(-1);
                    }
                    else
                    {
                        l.push_back((s.top()).second);
                    }
                }
            }
            s.push({a[i],i});
        }
        long long area=0;long long ans=0;
        for(int i=0;i<n;i++)
        {
            area=a[i]*(r[i]-l[i]-1);
            ans=max(ans,area);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends