/**41. First Missing Positive
 * Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.*/

//采用类似桶排序的思路，题中要求一个无序数组中最小的缺失正整数，最小的正整数是 1，数组的大小为 numsSize，所有桶的大小即为 1~numsSize
/*用桶对数组中的所有元素进行哈希，哈希完毕后，扫一遍哈希表，找出最小的为进行哈希的正整数值即可
 * 因为题目要求空间为常数，所以不能开一个数组进行哈希，就在原数组上进行哈希*/
int firstMissingPositive(int* nums, int numsSize)
{
    if(numsSize == 0)//数组大小为零，则缺失第一个正整数
        return 1;
    for(int i = 0 ; i < numsSize ; i++)//对桶范围内的所有元素进行哈希
    {
        //当发现超出桶范围的数，不考虑把其放入桶中；数为负时也不考虑放入；当数在桶的范围内且数不在其应该在的位置上时，通过交换把它放到位置上。并对交换后的位置不断哈希，使其也位置正确
        //这里一定要用 while, 用 if 的话，交换后 i 位置的数可能不在它应在的位置上
        while(nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i])//使 1~numsSize 大小范围的元素处于 0~numsSize的下标位置上
        {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    for(int i = 0 ; i < numsSize ; i++)//对桶进行扫描，找出第一个不在位置的数即为缺失的正整数
        if(nums[i] != i+1)
            return i+1;

    return numsSize+1;//完美哈希，则缺失的为桶范围外的第一个正整数
}

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    int test[] = {1,2,0};
    int fir = firstMissingPositive(test, 3);
    printf("first missing positive int is : %d\n",fir);
    return 0;
}