static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class OrderedStream {
public:
    OrderedStream(int n) { data.resize(n + 1); }
    
    vector<string> insert(int idKey, string value)
    {
        data[idKey] = value;
        
        vector<string> ans;
        if (ptr == idKey)
            while (ptr < data.size() && !data[ptr].empty())
                ans.push_back(data[ptr++]);
        return ans;
    }
    
private:
    int ptr = 1;
    vector<string> data;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */