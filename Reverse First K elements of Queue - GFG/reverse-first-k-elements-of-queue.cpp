//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    // vector<int>res;
    // int i=0;
    // while(i<k){
    //     res.push_back(q.front());
    //     q.pop();
    //     i++;
    // }
    // queue<int>ans;
    // for(int i=k-1;i>=0;i--){
    //     ans.push(res[i]);
    // }
    // while(!(q.empty())){
    //     ans.push(q.front());
    //     q.pop();
    // }
    // return ans;
    stack<int> s;
    queue<int> qq;

    // we pop first k elements from queue and push it in the stack.
    while (k-- > 0) {
        int a = q.front();
        q.pop();
        s.push(a);
    }

    // while stack is not empty, we push the elements into the new queue.
    while (!s.empty()) {
        int a = s.top();
        s.pop();
        qq.push(a);
    }

    // then we add rest of the elements of original queue to the new queue.
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        qq.push(a);
    }

    // returning the new queue.
    return qq;
}