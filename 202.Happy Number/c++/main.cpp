/**202. Happy Number
 * Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1*/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    unordered_set<int> been;//记录数字是否出现过，检测循环的产生

    long countDigits(int n)//计算数字的位数
    {
        long i = 1;
        while(n / i)
        {
            i *= 10;
        }
        return i/10;
    }

public:
    bool isHappy(int n)
    {
        been.insert(n);//记录以及进行分解加和的数
        long temp = 0;
        long count = countDigits(n);
        while(n > 0)//分解加和
        {
            temp += (n/count) * (n/count);
            n = n % count;
            count /= 10;
        }
        if(temp == 1) return true;//找到happy数,返回 true
        if(been.find(temp) != been.end()) return false;//之前出现过，出现循环，返回 false
        return isHappy(temp);//递归下去
    }
};

int main()
{
    bool test = Solution().isHappy(2026119321);
    cout<<"test:"<<test<<endl;

    return 0;
}