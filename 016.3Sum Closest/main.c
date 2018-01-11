/*16. 3Sum Closest
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int partation(int *nums,int l,int r)//排序相关
{
    int s = l;
    for(int i = l+1; i <= r; i++)
    {
        if(nums[i] < nums[l])
        {
            int temp = nums[s+1];
            nums[s+1] = nums[i];
            nums[i] = temp;
            s++;
        }
    }

    int temp = nums[l];
    nums[l] = nums[s];
    nums[s] = temp;
    return s;
}

void __quickSort(int *nums,int l,int r)//排序相关
{
    if(l < r)
    {
        int p = partation(nums,l,r);
        __quickSort(nums,l,p-1);
        __quickSort(nums,p+1,r);
    }
}

void quickSort(int *nums,int numsSize)//排序相关
{
    int l = 0;
    int r = numsSize - 1;
    __quickSort(nums,l,r);
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    if(numsSize == 3)//只有三个
        return (nums[0] + nums[1] + nums[2]);
    quickSort(nums,numsSize);//排序
    int small = nums[0] + nums[1] + nums[2];//3sum最小值
    int large = nums[numsSize-1] + nums[numsSize-2] + nums[numsSize-3];//3sum最大值
    if(target >= large)//大过上界
        return large;
    if(target <= small)//小过下界
        return small;

    int closest = small;//closest初始化为最小值

    for(int i = 0 ; i < numsSize - 2 ; i++)
    {
        int l = i + 1;
        int r = numsSize - 1;
        while( l < r)
        {
            int sum = (nums[l]+nums[i]+nums[r]);
            closest = (abs(target-closest)) > (abs(target-sum)) ? sum : closest;//更新closest的值

            if(closest == target)//找到直接返回
                return closest;
            if((sum) < target)//根据3sum的大小调整 l,r,不断逼近
                l++;
            else
                r--;
        }
    }


    return closest;
}

int main() {
    printf("Hello, World!\n");
    int a[] = {1,2,4,8,16,32,64,128};
    int closest = threeSumClosest(a,8,82);
    printf("closest is %d\n",closest);
    return 0;
}