//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to calculate the minimum number of operations required.
    long minOperations(vector<int> arr) {
        // code here
        int sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            sum += arr[i];
        }
        
        if(sum % arr.size() != 0)
        {
            return -1;
        }
        
        int k = sum/arr.size();
        int ans = 0;
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            ans = ans + abs(arr[i]-k);
        }
        
        return ans/2;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.minOperations(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends