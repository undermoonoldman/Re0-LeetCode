/*1. Two Sum
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

#include <stdio.h>
#include <stdlib.h>


void showArray(int *nums,int numsSize)
{
    for(int i = 0; i < numsSize; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int partation(int *nums,int l,int r,int *pre)
{
    int s = l;
    for(int i = l+1; i <= r; i++)
    {
        if(nums[i] < nums[l])
        {
            int tem = pre[s+1];
            pre[s+1] = pre[i];
            pre[i] = tem;
            int temp = nums[s+1];
            nums[s+1] = nums[i];
            nums[i] = temp;
            s++;
        }
    }
    int tem = pre[l];
    pre[l] = pre[s];
    pre[s] = tem;
    int temp = nums[l];
    nums[l] = nums[s];
    nums[s] = temp;
    return s;
}

void __quickSort(int *nums,int l,int r,int *pre)
{
    if(l < r)
    {
        int p = partation(nums,l,r,pre);
        __quickSort(nums,l,p-1,pre);
        __quickSort(nums,p+1,r,pre);
    }
}

void quickSort(int *nums,int numsSize,int *pre)
{
    int l = 0;
    int r = numsSize - 1;
    __quickSort(nums,l,r,pre);
}

 int* twoSum1(int* nums, int numsSize, int target)//双循环求解 O(n2)
 {
     int *ret = (int*)malloc(2 * sizeof(int));
     ret[0] = ret[1] = -1;
     for(int i = 0; i < numsSize-1; i++)//i < numsSize-1
     {
         for(int j = i+1; j <= numsSize-1; j++)//j从i+1开始，不用重复
         {
             if(nums[i] + nums[j] == target)
             {
                 ret[0] = i;
                 ret[1] = j;
             }
         }
     }
     return ret;
 }

int* twoSum2(int* nums, int numsSize, int target)//先排序后求解 O(nlogn),还可以用hash来做，O(n)
{
    int *ret = (int *) malloc(2 * sizeof(int));
    int pre[numsSize];//记录初始位置，排序后会打乱，维护该数组，排序之后能找到到最开始的位置
    for(int i = 0; i < numsSize; i++)
    {
        pre[i] = i;
    }
    ret[0] = ret[1] = -1;
    quickSort(nums, numsSize,pre);//排序
    int *l = nums;
    int *r = nums + numsSize - 1;
    while (l < r)//头尾双指针
    {
        if (*l + *r == target)
        {
            ret[0] = pre[l - nums];
            ret[1] = pre[r - nums];
            break;
        } else if (*l + *r < target)
            l++;
        else
            r--;
    }
    return ret;
}

void findTarget(int *nums,int numsSize,int target)
{
    int *p = twoSum2(nums,numsSize,target);
    printf("the target is in %d , %d\n",p[0],p[1]);
}
int main() {
    printf("Hello, World!\n");
    int a[4] = {3,2,4};
    showArray(a,3);
    findTarget(a,3,6);
    return 0;
}