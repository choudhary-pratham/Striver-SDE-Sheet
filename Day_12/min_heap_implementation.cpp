class Minheap{
private:
    vector<int>heap;
    int heapSize;
public:
    Minheap()
    {
        heapSize = 0;
    }
    void min_heapify(int ind)
    {
        int smallest = ind;
        int leftChild = 2*ind+1;
        int rightChild= 2*ind+2;
        if(leftChild<heapSize && heap[leftChild] < heap[smallest])
        {
            smallest = leftChild;
        }
        if(rightChild<heapSize && heap[rightChild] < heap[smallest])
        {
            smallest = rightChild;
        }
        if(ind != smallest)
        {
            swap(heap[ind],heap[smallest]);
            min_heapify(smallest);
        }
    }
    int pop()
    {
        int element = heap[0];
        heap[0] = heap[heapSize-1];
        heapSize--;
        heap.resize(heapSize);
        int ind = 0;
        min_heapify(ind);
        return element;
    }
    void percolate_up(int cur)
    {
        int parent = (cur-1)/2;
        while(cur!=0 && heap[parent] > heap[cur])
        {
            swap(heap[parent],heap[cur]);
            cur = parent;
            parent = (cur-1)/2;
        }
    }
    void push(int element)
    {
        heapSize += 1;
        heap.resize(heapSize);
        heap[heapSize-1] = element;
        int cur = heapSize-1;
        percolate_up(cur);
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    Minheap *h = new Minheap();
    vector<int>ans;
    for(int i=0;i<q.size();i++)
    {
        if(q[i][0] == 0)
        {
            h->push(q[i][1]);
        }
        else
        {
            ans.push_back(h->pop());
        }
    }
    return ans;
}
