#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head == NULL) return head;
    LinkedListNode<int> *dummy = head;
    //step 1
    while(dummy!=NULL)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(dummy->data);
        newNode->next = dummy->next;
        dummy->next = newNode;
        dummy = dummy->next->next;
    }
    //step 2
    dummy = head;
    while(dummy!=NULL)
    {
        if(dummy->random!=NULL)
            dummy->next->random = dummy->random->next;
        else 
            dummy->next->random = NULL;
        dummy = dummy->next->next;
    }
    //step 3
    dummy = head;
    LinkedListNode<int> *newHead = new LinkedListNode<int>(0);
    newHead->next = dummy->next;
    LinkedListNode<int> *temp = newHead;

    while(dummy!=NULL)
    {
        LinkedListNode<int> *iter = dummy->next->next;
        temp->next = dummy->next;
        dummy->next = iter;
        temp = temp->next;
        dummy = dummy->next;
    }
    return newHead->next;
}
