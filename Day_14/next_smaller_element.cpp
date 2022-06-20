#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int>nse(n,-1);
    stack<int>st;
    for(int i=arr.size()-1;i>=0;i--)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        if(!st.empty()) nse[i] = st.top();
        st.push(arr[i]);
    }
    return nse;
}