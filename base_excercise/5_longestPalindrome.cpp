/*************************************************************************
	> File Name: 5_longestPalindrome.cpp
	> Author: wanghao
	> Mail: wanghaodlut@163.com 
	> Created Time: 2021年06月19日 星期六 21时51分00秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int maxLen = 1;
        int begin = 0;
        if (len < 2)
        {
            return s;
        }

        // dp[i][j] show whether s[i...j] is plaindrome
        vector< vector<int> > dp(len, vector<int>(len));
        // palindrome length is 1
        for(int i = 0; i < len; i++)
        {
            dp[i][i] = true;
        }

        // plaindrome length > 1
        for (int L = 2; L <= len; L++)
        {
            for(int i = 0; i < len; i++)
            {
                int j = L + i -1;
                if (j >= len)
                {
                    break;
                }

                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else
                {
                    if (j - i < 3)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if(dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

int main()
{
	Solution solution;
	string s = "bb";
	
	cout << solution.longestPalindrome(s) << endl;
	
		
	return 0;
}
