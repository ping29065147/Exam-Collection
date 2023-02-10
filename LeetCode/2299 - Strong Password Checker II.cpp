static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool strongPasswordCheckerII(string password)
    {
        int n = password.size();
        if (n < 8) return false;

        int low = 0, up = 0, digit = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i && password[i] == password[i - 1]) return false;
            else if (islower(password[i])) ++low;
            else if (isupper(password[i])) ++up;
            else if (isdigit(password[i])) ++digit;
        }
        if (!low || !up || !digit || low + up + digit == n) return false;

        return true;
    }
};