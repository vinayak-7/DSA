//{ Driver Code Starts
#include <bits/stdc++.h>
#include <queue>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> arr, int k) {
        // Your code here
        priority_queue<int> pq;
        
        for(int i = 0 ; i < arr.size() ; i++){
            pq.push(arr[i]);
        }
        
        while(k > 1){
            pq.pop();
            k--;
        }
        
        
        return pq.top();
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.KthLargest(arr, k) << endl;
    }

    return 0;
}
// } Driver Code Ends