//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<string> nums;
        for(int i =1 ; i<= n ; i++)
            nums.push_back(to_string(i));
    
        while(k-1){
            next_permutation(nums.begin() , nums.end());
            k--;
        }
        
        string ans = "";
        for(auto x : nums) ans+= x;
        
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
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends