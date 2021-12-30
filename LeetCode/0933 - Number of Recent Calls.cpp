static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class RecentCounter {
public:
    RecentCounter() {}
    
    int ping(int t)
    {
        while (!Q.empty() && Q.front() + 3000 < t) Q.pop();
        Q.push(t);
        return Q.size();
    }
    
private:
    queue<int> Q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */