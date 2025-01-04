//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        unordered_map<int, int> mp;
        mp[arr[0]]++;
        int cnt = 0;
        for(int i=1; i<arr.size()-1; i++) {
            for(int j=i+1; j<arr.size(); j++) {
                if (mp.find(target - (arr[i]+arr[j])) != mp.end()) {
                    cnt += mp[target - (arr[i]+arr[j])];
                }
            }
            mp[arr[i]]++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends