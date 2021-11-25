static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int Max = 0;
        int tmp = 0;
        
        for (auto& i : nums)
        {            
            tmp = (tmp + i) * i;
            Max = max(Max, tmp);
        }  
        
        return Max;
    }
};