/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int guessNumber(int n)
    {
        if (guess(n) == 0) return n;
        
        int l = 1;
        int r = n;
        
        while(l < r)
        {
            n = l + (r - l) / 2;
            int x = guess(n);
            
            if (x == -1) r = n;
            else if (x == 1) l = n;
            else break;
        }
        
        return n;
    }
};