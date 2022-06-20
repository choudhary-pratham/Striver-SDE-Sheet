#include<stack>
class Queue {
    // Define the data members(if any) here.
    private:
    stack<int>input;
    stack<int>output;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(!output.empty())
        {
            int val = output.top();
            output.pop();
            return val;
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            if(output.empty()) return -1;
            int val = output.top();
            output.pop();
            return val;
        }
    }

    int peek() {
        // Implement the peek() function here.
         if(!output.empty())
        {
            return output.top();
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            if(output.empty()) return -1;
            return output.top();
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return input.empty() && output.empty();
    }
};