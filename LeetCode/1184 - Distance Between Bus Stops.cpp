static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination)
    {
        int cnt1 = 0, cnt2 = 0;
        int n = distance.size();
        
        if (start > destination) swap(start, destination);
        for (int i = start; i < destination; ++i) cnt1 += distance[i];
        for (int i = destination; i != start; i = (i + 1) % n) cnt2 += distance[i];
        
        return min(cnt1, cnt2);
    }
};