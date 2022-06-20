void sortedInsert(stack<int>&stack,int element)
{
    if(stack.empty() || stack.top()<=element)
    {
        stack.push(element);
        return;
    }
    else
    {
        int temp = stack.top();
        stack.pop();
        sortedInsert(stack,element);
        stack.push(temp);
    }
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(!stack.empty())
    {
        int temp = stack.top();
        stack.pop();
        sortStack(stack);
        sortedInsert(stack,temp);
    }
}