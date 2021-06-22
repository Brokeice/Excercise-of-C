#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0;
        int r = len - 1;
        int tmpArea = 0;

        while(l < r)
        {
            int maxArea = (height[l] < height[r] ? height[l]: height[r]) * (r - l);
            tmpArea = (maxArea > tmpArea ? maxArea: tmpArea);
            
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return tmpArea;
    }
};

int main()
{
    Solution solution;
    int a[9] = [1,8,6,2,5,4,8,3,7];
  
    cout << solution.maxArea(a) << endl;
    
    return;
}
