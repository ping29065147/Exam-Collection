static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_map<string, int> M;
        
        for (auto& s : emails)
        {
            auto it = s.find('@');
            auto it2 = s.find('+');
            string str = s.substr(0, min(it, it2));
            
            while(1)
            {
                auto it3 = str.find('.');
                if (it3 == string::npos) break;
                str.erase(str.begin() + it3);
            }
            
            str += s.substr(it, s.size());
            ++M[str];
        }
        
        return M.size();
    }
};