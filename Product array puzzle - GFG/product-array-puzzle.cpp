//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> ans;
        long long int product0 = 1 , product = 1;
        for(int i = 0 ; i < n ; i++)
        {
            product = product*nums[i];
        }
        
        if(product == 0)
        {
            int count = 0;
            for(int i = 0 ; i < n ; i++)
            {
                if(nums[i] == 0) 
                {
                    count++;
                }
                if(count > 1 || nums[i] != 0) product0 = product0*nums[i];
            }
            for(int i = 0 ; i < n ; i++)
            {
                if(nums[i] == 0) ans.push_back(product0);
                else ans.push_back(0);
            }
        }
        else{
            for(int i = 0 ; i < n ; i++)
            {
                long long int val = product/nums[i];
                ans.push_back(val);
            }
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends