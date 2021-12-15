static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countPrimeSetBits(int left, int right)
    {
        int cnt = 0;   
        
        getPrime();
        for (int i = left; i <= right; ++i) if (isPrime(i)) ++cnt;
        
        return cnt;
    }
    
    void getPrime()
    {
        V.resize(100, true);
        V[0] = V[1] = false;
        
        for (int i = 2; i < 100; ++i) if (V[i])
        {
            for (int j = i * 2; j < 100; j += i) V[j] = false;
        }
    }
    
    bool isPrime(int num)
    {
        int cnt = 0;
        
        while(num != 0)
        {
            if (num & 1) ++cnt;
            num >>= 1;   
        }
        
        return V[cnt];
    }
    
private:
    vector<bool> V;
};