//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to calculate the sum of distinct elements in the array.
    int sumOfDistinct(vector<int>& a) {
        // Your code goes here
        int sum = 0;
        
        for(int i = 0 ; i < a.size() ; i++)
        {
            if (a[abs(a[i]) - 1] >= 0) { 
                sum += abs(a[i]); 
                a[abs(a[i]) - 1] *= -1; 
            } 
        }
        
        return sum;
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
        cout << ob.sumOfDistinct(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends