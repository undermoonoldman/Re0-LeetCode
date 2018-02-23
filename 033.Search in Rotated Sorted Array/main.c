/*33. Search in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.*/

/*二分搜索的变种
 * 旋转后的数组有两种情况 a.前部有序 b.后方有序
 * 界定方法是判断 nums[mid] 与 nums[end]的大小，nums[mid] < nums[end]后方有序，nums[mid] > nums[end]前部有序
 * 根据 target 与 nums[mid] 的值决定在那一部分进一步搜索(递归)
 * 递归到底的情况 start >= end(同二分搜索)*/
int __search(int* nums, int start, int end, int target)
{
    int mid = (start + end) / 2;
    if(start >= end)//递归到底处理
    {
        if(nums[start] == target)
            return start;
        else
            return -1;
    }
    if(target == nums[mid])//直接找到
        return mid;
    if(nums[mid] < nums[end])//确定分组(后方有序)
    {
        if(target > nums[mid] && target <= nums[end])//优先界定有序的搜索边界
            return __search(nums, mid+1, end, target);//在后方进一步搜索
        else
            return __search(nums, start, mid-1, target);
    }
    else//前部有序
    {

        if(target < nums[mid] && target >= nums[start])
            return __search(nums, start, mid-1, target);
        else
            return __search(nums, mid+1, end, target);
    }
}

int search(int* nums, int numsSize, int target)
{
    if(numsSize == 0)
        return -1;
    if(numsSize == 1)
        return target == nums[0] ? 0 : -1;

    return __search(nums, 0, numsSize-1, target);
}

#include <stdio.h>

int main()
{
    printf("Hello, World!\n");
    int target = 1;
    int a[] = {3,1};
    int index = search(a, 2, target);
    printf("target is %d\n",target);
    if(index == -1)
        printf("couldn't find !\n");
    else
        printf("the index is %d\n",index);


    return 0;
}