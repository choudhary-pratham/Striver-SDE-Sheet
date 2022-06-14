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

Node *getListAfterReverseOperation(Node *head, int n, int arr[]){
	// Write your code here.
    if(head == NULL) return NULL;
    Node* dummy = head;
    int count = 1;
    while(dummy->next!=NULL)
    {
        dummy = dummy->next;
        count++;
    }
    Node* newHead = new Node(0);
    newHead->next = head;
    Node *pre = newHead,*cur = newHead,*nex = newHead;
    
    int i=0;
    while(i<n)
    {
        if(count == 0) break;
        if(arr[i] == 0) {
            i++;
            continue;
        }
        int x;
        cur = pre->next;
        nex = cur->next;
        if(count>=arr[i]) x = arr[i];
        else x = count;
        for(int j=1;j<=(x-1);j++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count-=x;
        i++;
    }
    return newHead->next;
}