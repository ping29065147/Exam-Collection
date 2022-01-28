static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int m = *max_element(candies.begin(), candies.end());
        vector<bool> ret;
        
        for (auto& i : candies) ret.push_back(i + extraCandies >= m ? true : false);
        
        return ret;
    }
};