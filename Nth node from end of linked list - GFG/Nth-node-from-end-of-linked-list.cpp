// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node *curr = head;
    int len = 0;

    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }

    if (n > len)
        return -1;

    int pos = len - n;
    Node *t = head;

    for (int i = 0; i < pos; i++)
    {
        t = t->next;
    }

    return t->data;
}
