/*15. 3Sum
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.*/
#include <stdio.h>
#include <stdlib.h>

/*three sum 本质上是 two sum问题的变种,two sum 是求数组中两数和等于定值的组合，本题 three sum 是求三数和等于定值(0)的组合，不同的是 two sum 中一个定值只有一个确定的组合
 * 而three sum中一个定值可能有多个组合，而且要考虑去重问题。如果用排列组合进行筛选的话很可能会超时。对于这个问题因为定值恒为 0 所有可以转化为先在数组中取一个数 first，再求 target为 0-firstpick 的 twosum
 * */

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



void twoSum(int* nums, int numsSize, int begin, int target, int *temp,int **ret,int *pCount)
{


    int *l = nums + begin;
    int *r = nums + numsSize - 1;
    while (l < r)//头尾双指针
    {
        if (*l + *r == target)
        {
            if((*l != *(l-1) || *r != *(r+1)) || (l == nums+begin && r == nums+numsSize-1))
            {
                temp = (int *) malloc(3 * sizeof(int));
                temp[0] = 0-target;
                temp[1] = *l;
                temp[2] = *r;
                //printf("the pCount = %d\n",*pCount);
                //printf("temp[0][1][2] = %d %d %d\n",temp[0],temp[1],temp[2]);
                ret[*pCount] = temp;
                //printf("ret[][1],[][2],[][3]:%d %d %d\n",ret[*pCount][0],ret[*pCount][1],ret[*pCount][2]);
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
                (*count) += 1;
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

int checkRepeat2(int *nums,int i)
{
    if(i == 0)
        return 0;
    return nums[i-1] == nums[i] ? 1 : 0;
}

int checkRepeat1(int *nums,int i)
{
    int check = 0;
    for(int j = 0 ; j < i ; j++)
    {
        if(nums[i] == nums[j])
            check = 1;
    }
    return check;
}

void countThreeSum(int *nums, int numsSize, int *count)
{
    quickSort(nums,numsSize);//先对数组排序，因为返回结果是数组的值，不是下标，顺序乱了也没关系(two sum是返回数组下标)
    for(int i = 0 ; i < numsSize-2 ; i++)//numsSize-1为尾下标，组合问题只要小于numsSize-2就行了
    {
        if(!checkRepeat2(nums,i))//相同数字只算一次，之后跳过
        {
            countTwoSum(nums,numsSize,i+1,0-nums[i],count);//在数组当前位置的后面，找值为0-num[i]的 two sum
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    if(numsSize < 3)//不足三个元素，不能组成三元组
        return NULL;
    int *count = (int*)malloc(sizeof(int));//统计符合条件的三元组的数目
    *count = 0;
    countThreeSum(nums, numsSize,count);//统计符合条件的三元组的数目
    *returnSize = *count;
    
    int **ret = (int**)malloc(sizeof(int*) * (*count));//数组指针用于保存返回结果
    int *temp;//生成元组的临时指针
    int *pCount = (int*)malloc(sizeof(int));//计数，确定保存位置
    *pCount = 0;
    for(int i = 0 ; i < numsSize-2 ; i++)
    {
        if(!checkRepeat2(nums,i))//检查重复，重复的只计算一次
            twoSum(nums,numsSize,i+1,0-nums[i],temp,ret,pCount);
    }
    return ret;
}

void showTriplets(int **ret, int *rS)//测试输出
{
    printf("rS = %d\n",*rS);
    for(int i = 0 ; i < *rS ; i++)
    {
        printf("the %dth Triplet:",i+1);
        for(int j = 0 ; j < 3 ; j++)
        {
            printf("%d ",ret[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Hello, World!\n");

    int b[] = {0,0,0,0};
    int *rS = (int*)malloc(sizeof(int));
    int **ret = threeSum(b,4,rS);
    showTriplets(ret,rS);
    return 0;
}