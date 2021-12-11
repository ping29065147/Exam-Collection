static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
    {
        for (auto& i : nums)
        {
            Q.push(i);
            if (Q.size() > k) Q.pop();
        }
        K = k;
    }
    
    int add(int val)
    {
        Q.push(val);
        if (Q.size() > K) Q.pop();
        return Q.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> Q;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */