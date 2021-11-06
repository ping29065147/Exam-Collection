static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class MinStack {
public:
    MinStack() {}
    
    void push(int val)
    {
        if (MS.empty() || MS.top() >= val) MS.push(val);
        S.push(val);
    }
    
    void pop()
    {
        if (MS.top() == S.top()) MS.pop();
        S.pop();
    }
    
    int top() { return S.top(); }
    
    int getMin() { return MS.top(); }
    
private:
    stack<int> S;
    stack<int> MS;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */