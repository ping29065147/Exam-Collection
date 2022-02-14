static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr)
    {
        int cnt = 0, len = 1, s = arr.size();
        
        while(len <= s)
        {
            for (int i = len; i <= s; ++i)
                for (int j = i - len; j != i; ++j)
                    cnt += arr[j];
            
            len += 2;
        }
        
        return cnt;
    }
};