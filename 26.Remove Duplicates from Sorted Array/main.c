/*26. Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.

去除重复元素*/
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize)//i,j前后错开，前后相同时，i 后移，找到 i,j 不同时，把当前 j+1 位置赋值成 i, i,j 同时后移
{
    if(numsSize <= 1)
        return numsSize;
    int i = 1;
    int j = 0;
    while(i < numsSize)//遍历一遍数组
    {
        if(nums[i] == nums[j])//相等，后移 i
            i++;
        else//找到 i,j 不相等，j+1 = i，然后 i,j 后移
        {
            nums[j+1] = nums[i];
            j++;
            i++;
        }
    }
    return j+1;
}

void showIntArray(int *array, int n)
{
    for(int i = 0 ; i < n ; i++)
        printf("%d ",array[i]);
    printf("\n");
}

int main() {
    printf("Hello, World!\n");
    int a[] = {1,2,2,3,3,3,4,5};
    showIntArray(a, 8);
    int len = removeDuplicates(a, 8);
    showIntArray(a, len);
    return 0;
}