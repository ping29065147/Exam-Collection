static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        unordered_map<int, int> M;
        
        for (auto& i : bills)
        {
            ++M[i];
            
            if (i == 5) continue;
            else if (i == 10)
            {
                if (M[5] - 1 >= 0) --M[5];
                else return false;
            }
            else if (i == 20)
            {
                if (M[10] - 1 >= 0 && M[5] - 1 >= 0) --M[10], --M[5];
                else if (M[5] - 3 >= 0) M[5] -= 3;
                else return false;
            }
        }
        
        return true;
    }
};