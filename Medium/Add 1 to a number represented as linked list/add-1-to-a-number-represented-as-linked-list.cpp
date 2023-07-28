//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL || head->next==NULL) return head;
        struct Node* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    Node* addOne(Node *first) 
    {
        // Your Code here
        // return head of list after adding one
        first=reverseList(first);
        Node* dummy=new Node(-1);
        Node* tmp=dummy;
        int carry=1;
        while(first != 0 || carry!=0){
            int sum = 0;
            if(first!=NULL){
                sum+=first->data;
                first=first->next;
            }
            sum+=carry;
            carry=sum/10;
            Node* node=new Node(sum%10);
            tmp->next=node;
            tmp=tmp->next;
        }
        dummy->next=reverseList(dummy->next);
        return dummy->next;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends