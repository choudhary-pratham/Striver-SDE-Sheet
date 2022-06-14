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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
	LinkedListNode<int>* newHead = NULL;
	while(head!=NULL)
	{
		LinkedListNode<int>* next = head->next;
		head->next = newHead;
		newHead = head;
		head = next;
	}
	return newHead;
}