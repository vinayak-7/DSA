//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class Node{
    public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k,int value)
    {
        key = k;
        val = value;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache
{
    private:
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0); 
    unordered_map<int,Node*> mp;
    int capacity;
    public:
    
    
    void addNode(int key, int val)
    {
        Node *createNode = new Node(key,val);
        Node *temp = head->next;
        head->next = createNode;
        temp->prev = createNode;
        createNode->next = temp;
        createNode->prev = head;
    }
    
    
    void deleteNode(Node* &node)
    {
        Node *pre = node->prev;
        Node *post = node->next;
        pre->next = post;
        post->prev = pre;
        delete(node);
    }
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(mp.find(key) != mp.end())
        {
            Node *foundNode = mp[key];
            int ans = foundNode->val;
            deleteNode(foundNode);
            addNode(key,ans);
            mp.erase(key);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        
        if(mp.find(key) != mp.end())
        {
            Node *toDelete = mp[key];
            mp.erase(key);
            deleteNode(toDelete);
        }
        else if(mp.size() == capacity)
        {
            Node *toDelete = tail->prev;
            mp.erase(toDelete->key);
            deleteNode(toDelete);
        }
        addNode(key,value);
        mp[key] = head->next;
    } 
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends