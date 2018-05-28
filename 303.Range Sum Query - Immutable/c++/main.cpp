/**
 * 303. Range Sum Query - Immutable
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。

 */
#include <iostream>
#include <vector>
using namespace std;

//线段树方法，不推荐，只有线段查询操作，没有线段更新操作，效率没有充分利用
class NumArray {
private:
    vector<int> data;
    vector<int> tree;

    int sum(int index, int l, int r, int i, int j){
        if(l == i && r == j)
            return tree[index];
        int mid = l + (r-l)/2;
        int lChild = 2*index + 1;
        int rChild = 2*index + 2;

        if(i > mid)
            return sum(rChild, mid+1, r, i, j);
        else if(j <= mid)
            return sum(lChild, l, mid, i, j);
        else
            return sum(lChild, l, mid, i, mid) + sum(rChild, mid+1, r, mid+1, j);
    }

    void build(int index, int l, int r){
        if(l == r){
            tree[index] = data[l];
            return;
        }

        int lChild = 2*index + 1;
        int rChild = 2*index + 2;
        int mid = l + (r-l)/2;
        build(lChild, l, mid);
        build(rChild, mid+1, r);
        tree[index] = tree[lChild] + tree[rChild];
    }
public:
    NumArray(vector<int> nums) {
        if(nums.size() > 0) {
            data = nums;
            tree = vector<int>(data.size() * 4, -9999);
            build(0, 0, data.size() - 1);
        }
    }



    int sumRange(int i, int j) {
        if(data.size() == 0)
            return NULL;
        if(i < 0 || i >= data.size() || j < 0 || j >= data.size() || i > j)
            return NULL;
        return sum(0, 0, data.size()-1, i, j);
    }
};

//加和数组，推荐，数组构建完成后没有更新操作，只有查询，效率较高
class NumArray1 {
private:
    vector<int> sum;//存储前 n 项的加和结果

public:
    NumArray1(vector<int> nums) {
        //初始化时直接构建加和结果
        if(nums.size() > 0) {
            sum = vector<int>(nums.size()+1, 0);
            sum[0] = 0;
            for(int i = 1 ; i < sum.size() ; i++)
                sum[i] = sum[i-1] + nums[i-1];

        }
    }


    //利用前 n 项和的加和数组相减计算得到范围加和的值
    int sumRange(int i, int j) {
        if(i < 0 || i >= sum.size()-1 || j < 0 || j >= sum.size()-1 || i > j)
            return NULL;
        return sum[j+1] - sum[i];
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray1 numArray = NumArray1(nums);
    cout<<numArray.sumRange(0, 2);
    return 0;
}