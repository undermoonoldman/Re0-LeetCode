/*27. Remove Element
Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.
移除数组中指定元素
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int __partition(int arr[], int l, int r)
{
    swap(&arr[l], &arr[rand() % (r-l+1) + l]);
    int i = l+1;
    int j = r;

    while(1)
    {
        while(arr[i] < arr[l] && i <= r) i++;
        while(arr[j] > arr[l] && j >= l+1) j--;

        if(i >= j) break;

        swap(&arr[i], &arr[j]);

        i++;
        j--;
    }
    swap(&arr[l], &arr[j]);
    return j;
}


void __quickSort(int arr[], int l, int r)
{
    if(l >= r)

        return;
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}


void quickSort(int arr[], int n)
{

    srand(time(NULL));

    __quickSort(arr, 0, n-1);
}

// int removeElement(int* nums, int numsSize, int val)//方法1，先排序，再把大于 val 的部分覆盖到等于 val 的部分
// {
//    quickSort(nums, numsSize);
//    int i = 0;
//    int j;
//    int ret = numsSize;
//    while(i < numsSize)
//    {
//        if(nums[i] != val)
//            i++;
//        else
//            break;
//    }

//    if(i >= numsSize)
//        return numsSize;
//    j = i;

//    while(i < numsSize)
//    {
//        if(nums[i] == val)
//        {
//            i++;
//            ret--;
//        }
//        else
//            break;
//    }

//    if(i >= numsSize)
//        return ret;

//    for(int k = i ; k < numsSize ; k++)
//        nums[j++] = nums[k];

//    return ret;
// }

int removeElement(int* nums, int numsSize, int val)//方法2，把不等于 val 的部分移到数组的前面，后面全等于 val的部分
{
    int pos = 0;
    for(int i = 0 ; i < numsSize ; i++)
    {
    	if(nums[i] != val)
    		nums[pos++] = nums[i];
    }
    return pos;
}

void showIntArray(int *array, int n)
{
    for(int i = 0 ; i < n ; i++)
        printf("%d ",array[i]);
    printf("\n");
}

int main() {
    printf("Hello, World!\n");
    int a[] = {3,2,2,3};
    showIntArray(a,4);
    int len = removeElement(a, 4, 3);
    showIntArray(a,len);
    return 0;
}