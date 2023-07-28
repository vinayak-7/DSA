//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends
class Solution
{
    public:
    Node* copyList(Node* head) {
        // Step 1: Create a new node for each original node and insert it after the original node.
        Node* current = head;
        Node* forward = NULL;
        
        while (current != NULL) {
            forward = current->next; // Save the next node in the original list.
            Node* newNode = new Node(current->data); // Create a new node with the same data as the current node.
            current->next = newNode; // Insert the new node after the current node in the original list.
            newNode->next = forward; // Set the next pointer of the new node to the saved next node.
            current = forward; // Move to the next node in the original list.
        }
        
        // Step 2: Set the arbitrary pointers of the new nodes based on the original nodes.
        current = head;
        while (current != NULL && current->next != NULL) {
            if (current->arb != NULL) {
                current->next->arb = current->arb->next; // Set the arbitrary pointer of the new node to the copied arbitrary node.
            }
            current = current->next->next; // Move to the next original node.
        }
        
        // Step 3: Separate the original and copied linked lists.
        current = head;
        Node* resultHead = current->next; // Save the head of the copied linked list.
        forward = NULL;
        while (current != NULL && current->next != NULL) {
            forward = current->next; // Save the next node in the copied list.
            current->next = forward->next; // Remove the copied node from the original list.
            current = forward; // Move to the next node in the copied list.
        }
        
        return resultHead; // Return the head of the copied linked list.
    }

};

//{ Driver Code Starts.


void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}



int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
// } Driver Code Ends