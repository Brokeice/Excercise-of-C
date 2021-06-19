#include <string>
#include <iostream>

using namespace std;

class Solution{
public:
    bool too_large(long long res){
        return res >= INT_MAX ||res <= INT_MIN;
    }

    int myAtoi(string s)
    {
        int i = 0;
        int len = s.length();
        int positivesign = 1;

        if (len == 0)
        {
            return 0;
        }

        // remove precursor space
        while (i < len && s[i] == ' ')
        {
            i++;
        }

        // check sign(+/-)
        if (isdigit(s[i]) == false && s[i] != '+' && s[i] != '-')
        {
            return 0;
        }

        // judge sign
        positivesign = (s[i] != '-') ? 1 : -1;

        // '-' exist, i++
        if (isdigit(s[i]) == false)
        {
            i++;
        }
        // calculate value
        long long res = 0;
        while (isdigit(s[i]) && i < len)
        {
            int digit = s[i] - '0';
            res = res * 10 + digit;
            bool ret = too_large(res * positivesign);
            if (ret)
            {
                if (positivesign > 0)
                {
                    return INT_MAX;
                }
                else 
                {
                    return INT_MIN;
                }
                
            }

            i++;
        }
        return (int)(res * positivesign);
    }
};

int main()
{
    Solution solution;
    string s = "2147483460";
    int res = solution.myAtoi(s);
    cout << res << endl;
    return 0;
}
