static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        vector<int> V(2, 0);
        
        for (auto& i : students) ++V[i];
        for (auto& i : sandwiches)
        {
            if (V[i] - 1 < 0) break;
            --V[i];
        }
        
        return V[0] + V[1];
    }
};