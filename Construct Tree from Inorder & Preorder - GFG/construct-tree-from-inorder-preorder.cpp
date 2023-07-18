//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* createTree(int inorder[],int inS , int inE , int preorder[], int preS , int preE , int n)
    {
        if(inS > inE || preS > preE) return NULL;
        
        Node* node = new Node(preorder[preS]);
        int index = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(inorder[i] == preorder[preS])
            {
                index = i;
                inorder[i] = -1;
                break;
            }
        }
        
        int numLeft = index - inS;
        
        node->left = createTree(inorder, inS, index-1, preorder, preS+1, preS+numLeft, n);
        node->right = createTree(inorder, index+1, inE, preorder, preS+numLeft+1, preE, n);
        
        return node;
    }
    Node* buildTree(int inorder[],int preorder[], int n)
    {
        // Code here
        return createTree(inorder,0,n-1,preorder,0,n-1,n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends