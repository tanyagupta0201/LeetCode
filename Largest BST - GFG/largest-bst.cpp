//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    vector<int> solve(Node *root)
    {
        // 1st edge case
        // if any node is not having either left node or right node
        if(root == NULL)
           return {1, 0, INT_MAX, INT_MIN};
           
        // 2nd edge case
        // if a node is leaf node -> it is always a BST
        if(!root->left && !root->right)
           return {1, 1, root->data, root->data};
           
        
        // we will find recursively from left as well as right
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        
        // if both left and right can form BST then there is a chance for the current node to form a BST
        if(l[0] == 1 && r[0] == 1)
        {
            int currVal = root->data;
            
            if(currVal > l[3] && currVal < r[2])
            {
                int mini = l[2], maxi = r[3];
                
                if(mini == INT_MAX)
                   mini = root->data;
                   
                if(maxi == INT_MIN)
                   maxi = root->data;
                
                return {1, l[1] + r[1] + 1, mini, maxi};
            }
            
        }
        
        // else portion
        return {0, max(l[1], r[1]), 0, 0};
        
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	// we are maintaining four things for each node
    	// { BST, size, min val, max val }
    	vector<int> v = solve(root);
    	
    	return v[1]; // returns the size
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends