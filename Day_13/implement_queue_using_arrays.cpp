struct node{
    int front;
    int rear;
    int size;
    int* arr;
};

class Queue {
private:
    node* q = new node();
public:
    Queue() {
        // Implement the Constructor
        q->front = 0;
        q->rear = 0;
        q->size = 5001;
        q->arr = new int[5001];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return q->rear == q->front;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q->arr[q->rear++] = data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        else return q->arr[q->front++];
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        else return q->arr[q->front];
    }
};