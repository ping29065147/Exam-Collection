static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> V(num_people, 0);
        int pos = 0, cnt = 0;
        
        while(candies > 0)
        {
            V[pos] += (candies >= ++cnt ? cnt : candies);
            candies -= cnt;
            pos = (pos + 1) % num_people;
        }
        
        return V;
    }
};