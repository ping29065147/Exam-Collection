static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> ret;
        int cnt = 0;
        
        for (auto& i : target)
        {
            while(i != ++cnt)
            {
                ret.push_back("Push");
                ret.push_back("Pop");
            }
            ret.push_back("Push");
        }
        
        return ret;
    }
};