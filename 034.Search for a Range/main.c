#include <stdlib.h>

/*34. Search for a Range
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].*/


/*双指针问题，扫描成功及时退出，左右指针碰撞终止循环
 * 无论找到结果与否，返回的数组分配的空间始终为两个整形
 * 注意把分配的大小赋值给 returnSize*/

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int l = 0;
    int r = numsSize - 1;
    while(l < r)
    {
        if(nums[l] == target && nums[r] == target)
            break;
        if(nums[l] != target)
            l++;
        if(nums[r] != target)
            r--;
    }
    int *ret = (int*)malloc(sizeof(int) * (2));
    *returnSize = 2;
    if(l >= r && nums[l] != target)
    {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    ret[0] = l;
    ret[1] = r;
    return ret;
}

void showArray(int* nums, int numsSize)
{
    for(int i = 0 ; i < numsSize ; i++)
        printf("%d ",nums[i]);
    printf("\n");
}

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    int* returnSize = (int*)malloc(sizeof(int));
    int a[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int* position = searchRange(a, 6, target, returnSize);
    showArray(a, 6);
    if(position[0] == -1)
        printf("couldn't find the position !\n");
    else
    {
        printf("finding the position\n");
        printf("begin: %d , end: %d\n",position[0],position[1]);
    }

    printf("the value of returnSize is %d\n",*returnSize);

    return 0;
}