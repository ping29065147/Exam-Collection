static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class MyHashMap {
public:
    MyHashMap() { V.resize(1000001, 1000001); }
    
    void put(int key, int value) { V[key] = value; }    
    int get(int key) { return V[key] == 1000001 ? -1 : V[key]; }  
    void remove(int key) { V[key] = 1000001; }
    
private:
    vector<int> V;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */