//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    vector<int> num, zero;

        // Store positive and negative numbers separately
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0 || arr[i] < 0) {
                num.push_back(arr[i]);
            } else {
                zero.push_back(arr[i]);
            }
        }

        // Rearrange the array with alternating positive and negative numbers
        int i = 0 , j = 0 ,k = 0;
        while (i < num.size()) {
            arr[k++] = num[i++];
        }

        // Add remaining positive or negative numbers to the end of the array
        while (j < zero.size()) {
            arr[k++] = zero[j++];
        }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends