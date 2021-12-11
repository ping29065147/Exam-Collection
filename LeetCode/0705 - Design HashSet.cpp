static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class MyHashSet {
public:
    MyHashSet() { V.resize(1000001, 0); }
    
    void add(int key) { V[key] = 1; }   
    void remove(int key) { V[key] = 0; }  
    bool contains(int key) { return V[key] == 1; }
    
private:
    vector<int> V;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */