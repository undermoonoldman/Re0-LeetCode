#include <stdlib.h>
#include <assert.h>

/**38. Count and Say
 * The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"*/


/*思路:输入 2，输出对 1 的描述，1 的描述为 "11"，输入 3 ，输出对 2 描述的描述，2 的描述为 "11"，描述的描述为 "21"
 * 可以看出，这是一个递推的描述方式. 初始条件为 1 的描述为 "1"*/

//一开始绊倒在数字向字符的转换上了，一个小坑

char numToChar(int n)//输入一个 0~9 的整数，输出该整数所对应的字符.例如输入 4 输出 '4'
{
    assert(n >= 0 && n <= 9);
    char ret = '0';
    ret = ret + n;
    return ret;
}

void doSay(char* input, char* output)
{
    char* p = input;
    char* q = output;
    while(*p != '\0')
    {
        int count = 1;//统计串中每个字符出现的次数,默认为 1
        while(p[0] == p[1])
        {
            p++;
            count++;
        }
        //生成的描述为，字符出现次数-字符
        *q = numToChar(count);//字符出现的次数
        q++;
        *q = *p;//所出现的字符
        q++;
        p++;
    }
    *q = '\0';
}

char* countAndSay(int n)
{
    if(n < 1)
        return NULL;
    char* left = malloc(10000);//用两个串来回倒换递推求出最后的结果
    char* right = malloc(10000);
    char* ret;
    strcpy(left, "1");
    if(n == 1)
        return left;
    for(int i = 1 ; i < n ; i++)//递推求解
    {
        if(i % 2 == 1)
        {
            doSay(left, right);
            ret = right;
        }

        else
        {
            doSay(right, left);
            ret = left;
        }
    }
    return ret;
}

#include <stdio.h>
#include <string.h>

int main() {
    printf("Hello, World!\n");
    char* test = countAndSay(4);
    printf("test is %s \n",test);
    return 0;
}