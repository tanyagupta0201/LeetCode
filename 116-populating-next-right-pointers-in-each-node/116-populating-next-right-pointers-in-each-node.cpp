/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        // if root is null return null
        if(root == NULL)
            return NULL;
        
        // Start with the first level (root's next is already null)
        Node* curr = root;
        
        // Start work beginning on the second level and onwards
        while(curr->left != NULL)
        {
            // Keep Track of the beginning of the next level
            Node* nextLevel = curr->left;
            
            // For each node on this level, populate the next pointer of the next level (its children)
            while(curr != NULL)
            {
                curr->left->next = curr->right;
                
                if(curr->next == NULL)
                    curr->right->next = NULL;
                else
                    curr->right->next = curr->next->left;
                
                // Move to next node on this level 
                curr = curr->next;
            }
            // Move to next level
            curr = nextLevel;
        }
        return root;
    }
};