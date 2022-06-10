#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *newHead = NULL;
    while(head!=NULL)
    {
        LinkedListNode<int> *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL) return true;
    LinkedListNode<int> *dummy = head;
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while(slow!=NULL)
    {
        if(slow->data != dummy->data) return false;
        slow = slow->next;
        dummy = dummy->next;
    }
    return true;
}