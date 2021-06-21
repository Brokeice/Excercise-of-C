#include <iostream>
#include <string>
#include <vector>

using namepace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        int goingDown = false;

        for(char c: s){
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1: -1;
        }
        string ret;
        for(string row: rows){
            ret += row;
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    string s = "PAYPALISHRING";
  
    cout << solution.convert(s, 3) << endl;
  
    return 0;
}
