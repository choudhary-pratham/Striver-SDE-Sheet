#include<stack>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int>right(n+1,n),left(n+1,-1);
    stack<int>st;
    for(int i = n-1;i>=0;i--)
    {
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(!st.empty()) right[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = 0;i < n;i++)
    {
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(!st.empty()) left[i] = st.top();
        st.push(i);
    }
    vector<int>ans(n+1,-1e9);
    for(int i = 0;i<n;i++)
    {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len],a[i]);
    }
    for(int i=n-1;i>=1;i--)
    {
        ans[i] = max(ans[i],ans[i+1]);
    }
    vector<int>res(n,0);
    for(int i=1;i<=n;i++)
    {
        res[i-1] = ans[i];
    }
    return res;
}