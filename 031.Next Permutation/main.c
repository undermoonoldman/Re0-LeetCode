/*31. Next Permutation
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1*/
/*nextPermutation的关键在于找到比当前数字稍大的最小数
 * 1.从后往前找到第一个升序的数
 * 2.从该升序数后面找到比升序数大的最小数，交换两数
 * 3.反转升序数位置后面的所有数(因为交换后该序列呈降序排列，反转后为升序，最小)
 * etc:处理多个重复数字问题，相同的数字取最后一个(这样交换后能保证为降序)*/

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

void showArray(int* nums, int numsSize)
{
    for(int i = 0 ; i < numsSize ; i++)
        printf("%d ",nums[i]);
    printf("\n");
}

#include <stdio.h>

int main()
{
    printf("Hello, World!\n");

    int a[] ={1,2,3,4};
    showArray(a,4);
    for(int i = 0 ; i < 6 ; i++)
    {
        nextPermutation(a,4);
        printf("the %dst permutation: ",i+1);
        showArray(a,4);
    }



    return 0;
}