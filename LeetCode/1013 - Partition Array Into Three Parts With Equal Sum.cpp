static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr)
    {
        int sum = 0, num = 0, cnt = 0;
        
        for (auto& i : arr) sum += i;
        if (sum % 3) return false;
        sum /= 3;
        
        for (auto& i : arr)
        {
            num += i;
            if (num == sum) ++cnt, num = 0;
        }
        
        return cnt >= 3;
    }
};