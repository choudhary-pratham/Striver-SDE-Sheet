// Stack class.
struct node
{
    int top;
    int size;
    int *arr;
    node()
    {
        top = -1;
    }
};
class Stack {
private:
    node* st = new node();
public:
    
    Stack(int capacity) {
        // Write your code here.
        st->top = -1;
        st->size = capacity;
        st->arr = new int[st->size];
    }

    void push(int num) {
        // Write your code here.
        if(st->top!=st->size-1)
            st->arr[++st->top] = num;
    }

    int pop() {
        // Write your code here.
        if(st->top == -1) return -1;
        else{
          int val = st->arr[st->top];
          st->top--;
          return val;;  
        } 
    }
    
    int top() {
        // Write your code here.
        return (st->top!=-1)?(st->arr[st->top]):-1;
    }
    
    int isEmpty() {
        // Write your code here.
        return (st->top == -1);
    }
    
    int isFull() {
        // Write your code here.
        return (st->top == st->size-1);
    }
    
};