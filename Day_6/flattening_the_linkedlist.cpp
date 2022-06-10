#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* mergeFlatten(Node* a,Node* b)
{
    Node* temp = new Node(0);
    Node* res = temp;
    while(a!=NULL && b!=NULL)
    {
        if(a->data<b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else
        {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }
    if(a) temp->child = a;
    else temp->child = b;
    res->child->next=NULL;
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head == NULL || head->next == NULL) return head;
    
    head->next = flattenLinkedList(head->next);
    
    head = mergeFlatten(head,head->next);
    
    return head;
}
