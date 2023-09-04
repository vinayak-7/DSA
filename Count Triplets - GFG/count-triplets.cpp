//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    vector<int> arr;
    while(head->next != NULL)
    {
        arr.push_back(head->data);
        head = head->next;
    }
    arr.push_back(head->data);
    int count = 0;
    int n = arr.size();
    // reverse(arr.begin(),arr.end());
    for(int i = 0 ; i < n-2 ; i++){
        int j = i + 1;
        int k = n-1;
        int sum = x - arr[i];
        // cout<< arr[i] << " ";
        // cout<<"sum:"<< sum <<endl;
        while(j < k){
            if(arr[j] + arr[k] == sum) 
            {
                count++;
                j++;
                k--;
            }
            else if(arr[j] + arr[k] < sum) j++;
            else k--;
        }
    }
    
    return count;
} 