static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes)
    {
        unordered_map<int, vector<int>> M;
        vector<vector<int>> ans;
        
        for (int i = 0; i < groupSizes.size(); ++i)
            M[groupSizes[i]].push_back(i);
        
        for(auto& [i, j] : M)
        {
            vector<int> t;
            
            for (int k = 0; k < j.size(); ++k)
            {
                t.push_back(j[k]);
                
                if ((k + 1) % i == 0)
                {
                    ans.push_back(t);
                    t.clear();
                }
            }
            
            if (!t.empty()) ans.push_back(t);
            
        }
        
        return ans;
    }
};