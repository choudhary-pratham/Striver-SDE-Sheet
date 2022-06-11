#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    if(head == NULL || head->next == NULL || k==0) return head;
    Node* dummy = head;
    int count=1;
    while(dummy->next!=NULL && ++count)
    {
        dummy = dummy->next;
    }
    dummy->next = head;
    k = (count - (k%count));
    
    while(k--) dummy = dummy->next;
    
    head = dummy->next;
    dummy->next = NULL;
    
    return head;
}