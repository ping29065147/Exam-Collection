static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();


class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small)
    {
        V.resize(4, 0);
        V[1] = big;
        V[2] = medium;
        V[3] = small;
    }
    
    bool addCar(int carType)
    {
        return V[carType]-- > 0;
    }
    
private:
    vector<int> V;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */