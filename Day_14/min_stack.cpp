// Implement class for minStack.
#include<stack>
#include<limits.h>
class minStack
{
	// Write your code here.
    stack<long long int >st;
	long long mini;
	public:
		
		// Constructor
		minStack() 
		{
            mini = INT_MAX;
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            long long val = num;
            if(st.empty()) {
                mini = val;
                st.push(val);
            }
            else
            {
                if(mini > val) 
                {
                    st.push(2*val*1LL-mini);
                    mini = val;
                }
                else{
                    st.push(val);
                }
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(st.empty()) return -1;
            long long  el = st.top();
            long long val = el;
            st.pop();
            if(el < mini)
            {
                val = mini;
                mini = 2*mini*1LL - el;
            }
            return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(st.empty()) return -1;
            if(st.top() < mini) return mini;
            else return st.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(st.empty()) return -1;
            return mini;
		}
};