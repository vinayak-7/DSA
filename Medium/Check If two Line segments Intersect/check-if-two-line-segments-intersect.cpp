//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int direction(int p[], int q[], int r[]){
    long long val = (long long)(q[1] - p[1]) * (r[0] - q[0]) - (long long) (q[0] - p[0]) * (r[1] - q[1]);
    if (val == 0) {
        return 0;
    }
    if (val > 0){
        return 1;
    }
    else {
        return -1;
    }
}

int func(int p[], int q[], int r[]){
    if (q[0] <= max(p[0] , r[0]) && q[0] >= min (p[0] ,r[0]) && q[1] <= max(p[1] , r[1]) && q[1] >= min(p[1] , r[1])){
        return 1;
    }
    else{
        return 0;
    }
}



class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        int d1 = direction(p1, q1, p2);
        int d2 = direction(p1, q1, q2);
        int d3 = direction(p2, q2, p1);
        int d4 = direction(p2, q2, q1);
        
        if (d1 != d2 && d3 != d4){
            return "true";
        }
        if(d1 == 0 && func(p1, q1, p2)) {
            return "true";
        }
        else if(d2 == 0 && func(p1 , q1, q2)) {
            return "true";
        }
        else if(d3 == 0 && func(p2 , q2, p1)) {
            return "true";
        }
        else if(d4 == 0 && func(p2 ,q2, q1)) {
            return "true";
        }
        return "false";
            
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends