bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<expression.size();i++)
    {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            st.push(expression[i]);
        }
        else
        {
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if((ch == '(' && expression[i] == ')') || (ch == '{' && expression[i] == '}') || (ch == '[' && expression[i] == ']'))
            {
                continue;
            }
            else{
                return false;
            }
        }
    }
    if(!st.empty()) return false;
    return true;
}