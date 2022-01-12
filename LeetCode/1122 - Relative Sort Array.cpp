static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_map<int, int> M;
        vector<int> ret;
        int S = arr2.size();
        
        for (auto& i : arr1)
        {
            ++M[i];
            if (find(arr2.begin(), arr2.end(), i) == arr2.end()) arr2.push_back(i);
        }
        
        sort(arr2.begin() + S, arr2.end());  
        
        for (auto& i : arr2) 
        {
            while (M[i]) 
            {
                ret.push_back(i);
                --M[i];
            }
        }
        
        return ret;
    }
};