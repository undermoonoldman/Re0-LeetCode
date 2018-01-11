/*4. Median of Two Sorted Arrays
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5*/

/*可以把两个数组归并后再进行查找，但这样时间复杂度应该为 O(m + n) 。转换思路，找两个数组的中位数，如果长度和为奇数，返回中间
 * 一个数的值，如果长度和为偶数，返回中间两个数的平均值，这样问题就转换成为了在两个数组寻找第k小的数的问题，运用二分查找的想法，
 * 在两个数组前面分别割出 k/2 个位置，凑出 k 个位置，假设前 k 小的数都在这里面，如果前一个数组 k/2 位置比后一个数组 k/2 位置的
 * 数小，则说明第 k 小的数肯定不在前数组前 k/2 ，可能在前数组后 k/2 或后数组中，这样就把前数组的前 k/2切掉了，问题转换成了在前数组的后
 * k/2 跟后数组中寻找第 k-k/2小的数(反之当前数组 k/2 位置比后数组 k/2 位置大时，切掉后数组的部分) 这样问题就可以转换为一个递归的求解
 * 递归到底的几种条件，A.两数组有空，问题变成单数组问题，直接返回结果 B.经过不断切割，k 变成了 1 ，问题变成了在两数组中找最小值，比较后返回
 * C.不容易想到的，当前数组 k/2 位置与后数组 K/2 位置相等时，说明凑出来的 k 个位置的数都比剩下的部分小，第 k 小的数一定就在 k 个位置中，也就是前后
 * 数组的 k/2 位置，直接返回即可*/

#include <stdio.h>
int getKthInTwoArrays(int *nums1,int nums1Size,int *nums2,int nums2Size,int k)
{
    if(nums1Size > nums2Size)//假设nums1Size大于nums2Size，若不成立调转参数即可
        return getKthInTwoArrays(nums2,nums2Size,nums1,nums1Size,k);
    if(nums1Size == 0)//递归到底，一个数组为空
        return nums2[k-1];
    if(nums2Size == 0)//递归到底，另一个数组为空
        return nums1[k-1];
    if(k == 1)//递归到底问题退化求成两数组最小数问题
        return nums1[0] > nums2[0] ? nums2[0] : nums1[0];

    int l1 = nums1Size > k/2 ? k/2 : nums1Size;//拼凑 k/2 考虑数组长度过小的问题
    int l2 = k - l1;//两部分凑出 k


    if(nums1[l1-1] < nums2[l2-1])//前数组 k/2 较小，切分前数组 k/2 部分，后数组不动
        return getKthInTwoArrays(nums1+l1,nums1Size-l1,nums2,nums2Size,k-l1);
    else if(nums1[l1-1] > nums2[l2-1])//后数组 k/2 较小，切分后数组 k/2 部分，前数组不动
        return getKthInTwoArrays(nums1,nums1Size,nums2+l2,nums2Size-l2,k-l2);
    else
        return nums1[l1-1];//递归到底，完美切割凑出了前 k 小个数都在两数组左边(右比左大，两数组左半边的最大值相等，故前 k 小都在左半边)
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int size = nums1Size + nums2Size;

    if(size % 2 == 1)
        return (double)getKthInTwoArrays(nums1,nums1Size,nums2,nums2Size,size/2+1);//长度和为奇数返回单值
    else//长度和为偶数返回两数的平均值
        return (double)((getKthInTwoArrays(nums1,nums1Size,nums2,nums2Size,size/2+1) + getKthInTwoArrays(nums1,nums1Size,nums2,nums2Size,size/2)) / 2.0);
}
int main() {
    printf("Hello, World!\n");

    int a[] = {1,3,5};
    int b[] = {2,4};
    double median = findMedianSortedArrays(a,3,b,2);
    printf("the median is %f\n",median);
    return 0;
}