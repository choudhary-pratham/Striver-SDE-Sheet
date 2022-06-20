#include<queue>
class Stack {
	// Define the data members.
   private:
    queue<int>q1;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
        int size = q1.size();
        for(int i=0;i<size-1;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(!q1.empty()) {
            int val = q1.front();
            q1.pop();
            return val;
        }
        else{
            return -1;
        }
    }

    int top() {
        // Implement the top() function.
        return (!q1.empty())?q1.front():-1;
    }
};