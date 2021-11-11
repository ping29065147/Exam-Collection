static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) { S1.push(x); }
    
    int pop()
    {
        convert();
        
        int tmp = S2.top();
        S2.pop();
        return tmp;
    }
    
    int peek()
    {
        convert();
        return S2.top();
    }
    
    bool empty() { return S1.empty() && S2.empty(); }
    
private:
    stack<int> S1, S2;
    
    void convert()
    {
        if (S2.empty())
        {
            while(!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */