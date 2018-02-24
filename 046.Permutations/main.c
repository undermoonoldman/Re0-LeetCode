#include <stdlib.h>

/*46. Permutations
 * Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/



void showArray(int* nums, int numsSize)
{
    for(int i = 0 ; i < numsSize ; i++)
        printf("%d ",nums[i]);
    printf("\n");
}

void showDoubleDimensionalArray(int** nums, int numsSize, int eachSize)
{
    for(int i = 1 ; i <= numsSize ; i++)
    {
        printf("%d: ",i);
        showArray(nums[i-1], eachSize);
    }
}

int computePermutationNumber(int numsSize)
{
    if(numsSize == 1)
        return 1;
    return numsSize * computePermutationNumber(numsSize-1);
}

void nextPermutation(int* nums, int numsSize)
{
    int target = numsSize;
    int next = -1;
    for(int i  = numsSize - 1; i >= 1 ; i--)//找升序数
    {
        if(nums[i-1] < nums[i])
        {
            target = i - 1;
            break;
        }
    }
    if(target == numsSize)//全为降序，反转整个序列
    {
        int l = 0;
        int r = numsSize - 1;
        while(l < r)
        {
            int temp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = temp;
        }
    }
    else
    {
        next = target + 1;
        for(int j = target + 1 ; j <= numsSize - 1 ; j++)//找最小的大数
            if(nums[j] <= nums[next] && nums[j] > nums[target])//nums[j] <= nums[next]考虑了相等的问题
                next = j;

        int temp = nums[target];
        nums[target] = nums[next];
        nums[next] = temp;

        int l = target+1;
        int r = numsSize - 1;
        while(l < r)//反转降序序列
        {
            int temp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = temp;
        }
    }
}

/*没用递归，因为给定的是集合(无重复)，所以生成的组合数可以阶乘得到
 * 连续进行 n 次 nextPermutation() 得到所有的组合，储存起来即可*/

int** permute(int* nums, int numsSize, int* returnSize)
{
    int sz = computePermutationNumber(numsSize);
    *returnSize = sz;
    int* temp;
    int **ret = (int**)malloc(sizeof(int*) * sz);
    for(int i = 0 ; i < sz ; i++)
    {
        nextPermutation(nums, numsSize);
        temp = (int*)malloc(sizeof(int));
        memcpy(temp, nums, sizeof(int)*numsSize);
        ret[i] = temp;
    }
    return ret;
}



#include <stdio.h>
#include <string.h>

int main()
{
    printf("Hello, World!\n");
    int a[] = {1,2,3};
    int* returnSize = (int*)malloc(sizeof(int));
    int** ret = permute(a, 3, returnSize);
    showDoubleDimensionalArray(ret, *returnSize, 3);
    return 0;
}