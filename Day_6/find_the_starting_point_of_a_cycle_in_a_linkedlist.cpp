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

Node *firstNode(Node *head)
{
	//    Write your code here.
    if(head == NULL || head->next == NULL) return NULL;
    Node *slow = head;
    Node *fast = head;
    
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow !=fast && slow && fast && fast->next);
    fast = head;
    while(slow!=fast && slow && fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}