static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reformatDate(string date)
    {
        unordered_map<string, string> M{{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        stringstream ss(date);
        string d, m, y;
        
        ss >> d >> m >> y;
        d = d.substr(0, d.length() - 2);
        if (d.length() == 1) d = "0" + d;
        
        return y + "-" + M[m] + "-" + d;
    }
};