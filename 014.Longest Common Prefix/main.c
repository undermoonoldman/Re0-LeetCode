/*14. Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *a = "ab";
char *b = "abc";
char *c = "afcd";
char **strs;//测试用

char* longestCommonPrefix(char** strs, int strsSize)
{
    char *ret;//保存返回结果
    if(strsSize == 0)//特殊情况
        return "";
    if(strsSize == 1)//字符串数组只有一个，自己就是
        return strs[0];
    int strsIndex = 0;//字符串数组指示器
    int matchIndex = 0;//最长公共前缀的长度
    char check;//上次匹配的字符
    char *p = strs[0];//字符串数组迭代指针
    int breakCheck = 0;//中断检查
    while(1)
    {
        for(check = strs[strsIndex][matchIndex] ; strsIndex <= strsSize-1 ; p = strs[++strsIndex])//从[0][j]开始匹配，不断匹配每个串的[i][j]
        {
            if(check == '\0')//串尾
            {
                matchIndex--;//匹配长度回滚一位
                breakCheck = 1;//中断
                break;
            }


            if(check == p[matchIndex])//当前串的[i][j]位置与check是否匹配
                check = p[matchIndex];
            else
            {
                matchIndex--;
                breakCheck = 1;
                break;
            }

        }
         if(breakCheck == 0)//，非中断退出，所有串的[j]位置都匹配成功，尝试匹配所有串的[j+1]位置
        {
            matchIndex++;
            strsIndex = 0;
            p = strs[strsIndex];
        }

        else//中断退出，退出循环
            break;
    }
    if(matchIndex == -1)
        return "";//没有一位匹配，返回空串
    else//拷贝匹配成功的串
    {
        ret = (char*)malloc(sizeof(char) * (matchIndex+1+1));
        ret = strncpy(ret,strs[0],matchIndex+1);
        ret[matchIndex+1] = '\0';
    }
    return ret;
}

int main() {
    printf("Hello, World!\n");
    strs = (char**)malloc(sizeof(char*) * 3);
    strs[0] = a;
    strs[1] = b;
    strs[2] = c;
    char *result = longestCommonPrefix(strs,3);
    printf("result is %s\n",result);
    return 0;
}