/**
 * 307. Range Sum Query - Mutable
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.


 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

示例:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
说明:

数组仅可以在 update 函数下进行修改。
你可以认为调用 update 函数和 sumRange 函数的次数是相等的。
 */
#include <iostream>
#include <vector>
using namespace std;


class NumArray {
private:
    vector<int> data;//存储原始数据
    vector<int> tree;//存储区间数据，本题中存储的是区间的加和

    //在以某结点为根的线段树计算区间和，index为根结点的位置，l,r 标识了根结点所对应的区间， i,j  是待求和的区间
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
    //在以某结点为根的线段树更新某位置的结点的值，并维护区间和的变化，index为根结点的位置，l,r 标识了根结点所对应的区间，i 是要更改的位置
    void update(int index, int l, int r, int i, int val){
        if(l == r){
            tree[index] = val;
            return;
        }
        int mid = l + (r-l)/2;
        int lChild = 2*index + 1;
        int rChild = 2*index + 2;

        if(i > mid)
            update(rChild, mid+1, r, i, val);
        else if(i <= mid)
            update(lChild, l, mid, i, val);
        tree[index] = tree[lChild] + tree[rChild];
    }

    //在以某结点为根构建线段树，index为根结点的位置，l,r 标识了根结点所对应的区间
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
            tree = vector<int>(data.size() * 4, -9999);//线段树开辟的空间为实际数据空间的四倍
            build(0, 0, data.size() - 1);//执行线段树构建操作
        }
    }

    //线段树区间求和
    int sumRange(int i, int j) {
        //传入空数组，未构建树，不做处理
        if(data.size() == 0)
            return NULL;
        //区间非法
        if(i < 0 || i >= data.size() || j < 0 || j >= data.size() || i > j)
            return NULL;
        return sum(0, 0, data.size()-1, i, j);
    }

    void update(int i, int val) {
        //先判断更新下标的合法性
        if(i >= 0 && i < data.size()){
            data[i] = val;
            update(0, 0, data.size()-1, i, val);
        }
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray numArray = NumArray(nums);
    cout<<numArray.sumRange(0, 2)<<endl;
    numArray.update(1, 2);
    cout<<numArray.sumRange(0, 2)<<endl;
    return 0;
}