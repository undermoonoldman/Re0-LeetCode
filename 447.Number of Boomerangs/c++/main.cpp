/**447. Number of Boomerangs
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*本题要求到其余两点距离相同的三元组点的排列，注意是排列(可以向前查找)*/

class Solution
{
private:
    int distance(pair<int, int> a, pair<int ,int> b)//两点间距离计算(距离的平方)
    {
        int res = (b.second - a.second) * (b.second - a.second) + (b.first - a.first) * (b.first - a.first);
        return res;
    }

public:
    int numberOfBoomerangs(vector<pair<int, int>>& points)//每次选取一个点，求得其他点到该点的距离，对距离进行统计,如果发现某个距离有超过一个点，则可以找到三元组，把能构成的排列数计算出来
    {
        int count = 0;//排列数计数器
        for(int i = 0 ; i < points.size() ; i++)//选取一个点
        {
            unordered_map<int, int> disTo;//到该点距离统计
            for(int j = 0 ; j < points.size() ; j++)//统计相同距离的频次
                if(j != i)
                    disTo[distance(points[i], points[j])]++;

            unordered_map<int, int> :: iterator ite;
            for(ite = disTo.begin() ; ite != disTo.end() ; ite++)//找出频次大于 1 的点，计算生成的排列总数，更新计数器
                if(ite->second > 1)
                    count += (ite->second * (ite->second - 1));

        }
        return count;
    }
};

int main()
{
    pair<int, int> a(0, 0);
    pair<int, int> b(1, 0);
    pair<int, int> c(2, 0);
    vector<pair<int, int>> points = {a, b, c};


    int ret = Solution().numberOfBoomerangs(points);
    cout<<ret;
    return 0;
}