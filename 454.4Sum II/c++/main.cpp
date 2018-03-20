/**454. 4Sum II
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)//暴力 o(N*N*N*N)不可用，使用 twoSum的查找表后 o(N*N)
    {
        unordered_map<int, int> twoSum;//把 C D 加和的结果所有可能放入 map
        int count = 0;//计数器
        for(int i = 0 ; i < C.size() ; i++)//把 C D 加和的结果所有可能放入 map
            for(int j = 0 ; j < D.size() ; j++)
                twoSum[C[i] + D[j]]++;

        for(int i = 0 ; i < A.size() ; i++)//对 AB 的每一种组合，看 map 中是否能找到加和为零的 CD 组合，找到就更新计数器
            for(int j = 0 ; j < B.size() ; j++)
                if(twoSum.find((-A[i] - B[j])) != twoSum.end())
                    count += twoSum[(-A[i] - B[j])];
        return count;
    }
};

int main()
{
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    int ret = Solution().fourSumCount(A, B, C, D);
    cout<<ret;
    return 0;
}