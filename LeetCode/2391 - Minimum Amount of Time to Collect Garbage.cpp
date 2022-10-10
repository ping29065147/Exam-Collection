static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        vector<int> car(3, 0);
        unordered_map<char, int> M = {{'P', 0}, {'G', 1}, {'M', 2}};
        int cnt = 0;
        
        for(int i = 0; i < garbage.size(); ++i)
        {
            for (auto& c : garbage[i])
            {
                for (int j = car[M[c]]; j < i; ++j) cnt += travel[j];
                car[M[c]] = i;
                ++cnt;              
            }
        }       
        
        return cnt;
    }
};