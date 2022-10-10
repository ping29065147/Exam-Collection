static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle)
    {
        R = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for (int i = row1; i <= row2; ++i)
            for (int j = col1; j <= col2; ++j)
                R[i][j] = newValue;
    }
    
    int getValue(int row, int col)
    {
        return R[row][col];
    }
    
private:
    vector<vector<int>> R;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */