/*18. 4Sum
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]*/
/*通用解法，递归转换 ksum 为 k-1sum ，递归到底的情况为问题转换为 2sum*/
#include <stdio.h>
#include <stdlib.h>
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



void twoSum(int* nums, int numsSize, int begin, int target, int *temp, int **ret, int *pCount, int total)
{


    int *l = nums + begin;
    int *r = nums + numsSize - 1;
    while (l < r)//头尾双指针
    {
        if (*l + *r == target)
        {
            if((*l != *(l-1) || *r != *(r+1)) || (l == nums+begin && r == nums+numsSize-1))
            {
                temp[total-2] = *l;
                temp[total-1] = *r;
                //printf("写最后两位，值为: %d %d\n",temp[total-2],temp[total-1]);
                int *temporary = (int*)malloc(sizeof(int) * total);
                for(int i = 0 ; i < total ; i++)
                {
                    temporary[i] = temp[i];
                    //printf("temporary[%d] = %d ,",i,temporary[i]);
                }
                ret[*pCount] = temporary;
                (*pCount) += 1;
            }
            l++;
            r--;
        } else if (*l + *r < target)
            l++;
        else
            r--;
    }
    return;
}

void countTwoSum(int* nums, int numsSize, int begin, int target,int *count)//
{
    int *l = nums + begin;//与 two sum 不同的是，这里的 l 初始值不是数组头了
    int *r = nums + numsSize - 1;
    while (l < r)//头尾双指针
    {
        if (*l + *r == target)
        {
            if((*l != *(l-1) || *r != *(r+1)) || (l == nums+begin && r == nums+numsSize-1))//相同位置只找一次
            {
                //printf("找到最后两位值为: %d  %d\n",*l,*r);
                (*count) += 1;
                //printf("这是第%d个结果\n",*count);
            }
            l++;
            r--;
        }
        else if (*l + *r < target)
            l++;
        else
            r--;
    }
    return;
}

int checkRepeat(int *nums,int i)
{
    if(i == 0)
        return 0;
    return nums[i-1] == nums[i] ? 1 : 0;
}

void countKSum(int *nums, int numSize, int begin, int target, int *count, int k)
{
    if(numSize - begin < k)//可选元素过少
        return;
    if(k == 2)//递归到底
    {
        countTwoSum(nums,numSize,begin,target,count);
        return;
    }

    for(int i = begin ; i < numSize-2 ; i++)//递归转换
    {
        if(!checkRepeat(nums,i) || i == begin)//初次选取时不计算重复
        {
            //printf("检查第%d位，尝试值为: %d ",k,nums[i]);
            countKSum(nums,numSize,i+1,target-nums[i],count,k-1);
        }

    }
}

void kSum(int *nums, int numSize, int begin, int target, int **ret, int *temp, int k, int *pCount , int total)
{
    if(numSize - begin < k)
        return;
    if(k == 2)
    {
        twoSum(nums,numSize,begin,target,temp,ret,pCount,total);
        return;
    }
    for(int i = begin ; i < numSize-2 ; i++)
    {
        if(!checkRepeat(nums,i) || i == begin)//初次选取时不计算重复
        {
            //printf("写第%d位，值为: %d ",k,nums[i]);
            temp[total-k] = nums[i];
            kSum(nums, numSize, i+1, target-nums[i], ret, temp, k-1,pCount,total);
        }
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
    if(numsSize < 4)//过小
        return NULL;
    quickSort(nums,numsSize);//排序整理
    int *count = (int*)malloc(sizeof(int));
    *count = 0;
    countKSum(nums,numsSize,0,target,count,4);
    *returnSize = *count;
    //printf("count = %d\n",*count);
    int **ret = (int**)malloc(sizeof(int*) * (*count));
    int *pCount = (int*)malloc(sizeof(int));
    *pCount = 0;
    int *temp = (int*)malloc(sizeof(int) * 4);
    kSum(nums,numsSize,0,target,ret,temp,4,pCount,4);
    return ret;
}

void showQuadruplets(int **ret, int *rS)//测试输出
{
    printf("rS = %d\n",*rS);
    int *p;
    for(int i = 0 ; i < *rS ; i++)
    {
        printf("the %dth quadruplet:",i+1);
        p = ret[i];
        for(int j = 0 ; j < 4 ; j++)
        {
            printf("%d ",p[j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Hello, World!\n");

    int b[] = {1, 0, -1, 0, -2, 2};
    int *rS = (int*)malloc(sizeof(int));
    int **ret;
    ret = fourSum(b,6,0,rS);
    showQuadruplets(ret,rS);
    return 0;
}