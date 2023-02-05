static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<double> convertTemperature(double celsius)
    {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};