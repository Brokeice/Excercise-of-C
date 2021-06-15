/*************************************************************************
	> File Name: twosum.c
	> Author: wanghao
	> Mail: wanghaodlut@163.com 
	> Created Time: 2021年05月23日 星期日 21时43分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for (int i = 0; i < numsSize; ++i) 
	{
        for (int j = i + 1; j < numsSize; ++j) 
	       {
                if (nums[i] + nums[j] == target)
                 {
                    int* ret = malloc(sizeof(int) * 2);
                    ret[0] = i, ret[1] = j;
                    *returnSize = 2;
                    return ret;
                 }
            }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;
    int *ret;

    ret = twoSum(nums, 4, target, &returnSize);

    printf("ret 1: %d, ret 2: %d\n", ret[0], ret[1]);


    return 0;
}
