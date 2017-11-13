/*11. Container With Most Water
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.*/

#include <stdio.h>

int max(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int min(int a,int b)
{
    if(a > b)
        return b;
    else
        return a;
}
/*就是求平行四边形的面积，可以双循环遍历，要减少遍历次数，用l,r两个指针从头尾分别遍历*/
//两条线与x轴围成的面积 底为r-l 高为l,r两条线中较短的一条 计算完当前面积后，更新l,r中较短一条边的长度，直到l,r相遇终止，确保了面积最大的情况在终止时已经被遍历过了
int maxArea(int* height, int heightSize)
{
    int *l = height;
    int *r = height + heightSize - 1;
    int maxArea = 0;
    while(l < r)
    {
        maxArea = max(maxArea,(r - l) * min(*l,*r));
        if(*l > *r)
            r--;
        else
            l++;
    }
    return maxArea;
}

int main() {
    printf("Hello, World!\n");
    int a[] = {2,3,3,2};
    int maxarea = maxArea(a,4);
    printf("maxarea is %d\n",maxarea);
    return 0;
}