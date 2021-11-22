static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        long M1, M2, M3;
        M1 = M2 = M3 = LONG_MIN;
        
        for (auto& i : nums)
        {
            if (i > M1) M3 = M2, M2 = M1, M1 = i;
            else if (i > M2 && i < M1) M3 = M2, M2 = i;
            else if (i > M3 && i < M2) M3 = i;
        }
        
        return (M3 == LONG_MIN || M3 == M2 ? M1 : M3);
    }
};