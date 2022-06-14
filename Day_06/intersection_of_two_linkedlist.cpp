#include <bits/stdc++.h> 
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int findIntersection(Node *l1, Node *l2)
{
    //Write your code here
    if(l1 == NULL || l2 == NULL) return NULL;
    Node *a = l1;
    Node *b = l2;
    
    while(a!=b)
    {
        a = a == NULL?l2:a->next;
        b = b == NULL?l1:b->next;
    }
    return (a == NULL?-1:a->data);
}