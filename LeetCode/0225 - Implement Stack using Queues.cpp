static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class MyStack {
public:    
    MyStack() {}
    
    void push(int x)
    {
        Q.push(x);
        for (int i = 0; i < Q.size() - 1; ++i)
        {
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    int pop()
    {
        int tmp = Q.front();
        Q.pop();
        return tmp;
    }
    
    int top() { return Q.front(); }
    
    bool empty() { return Q.empty(); }
    
private:  
    queue<int> Q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */