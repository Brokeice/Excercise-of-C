/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 /* qsort的比较函数 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int first = 0;
    int second = 0;
    int third = 0;
    int target = 0;
    int **ret = NULL;

    // 记录返回的行数位0
    *returnSize = 0;
    // 输入为空，或者元素个数小于3则返回NULL
    if(nums == NULL || numsSize < 3)
    {
        return NULL;
    }
    // 将数组升序排列
    qsort(nums, numsSize, sizeof(int), cmp);

    // 分配返回数组、返回数组的列数
    ret = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));

    for(first; first < numsSize; first++)
    {
        if (nums[first] > 0)
        {
            break;
        }
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }
        // c对应的指针指向数组最右端
        third = numsSize - 1;
        target = -nums[first];
        for(second = first +1; second < numsSize; second++)
        {
            //需要和上一次枚举的数不同
            if(second > first +1 && nums[second] == nums[second - 1])
            {
                continue;
            } 
            //需要保证b的位置在c的左侧
            while (second < third && nums[second] + nums[third] > target)
            {
                third--;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third)
            {
                break;
            }
            if (nums[second] + nums[third] == target)
            {
                ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
                ret[*returnSize][0] = nums[first];
                ret[*returnSize][1] = nums[second];
                ret[*returnSize][2] = nums[third]; 
                /* 返回数组当前行的列数为3 */
                (*returnColumnSizes)[*returnSize] = 3;
                /* 返回数组的行数自加1 */
                (*returnSize)++;
            }
        }
    }
    return ret;
}
