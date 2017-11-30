/*22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/
//卡特兰数的经典应用之一
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void generateCount(int n, int *count, int l, int r, int k)
{
    if(l == 0 && r == 0)
    {
        (*count) += 1;
        return;
    }
    if(l > 0)
    {
        generateCount(n,count,l-1,r,k+1);
    }
    if(r > 0 && l < r)
    {
        generateCount(n,count,l,r-1,k+1);
    }
}

void createParenthesis(int n, int *pCount, char *temp, char **ret, int l, int r, int k)
{
    if(l == 0 && r == 0)
    {
        printf("k = %d\n",k);
        printf("temp = %s\n",temp);

        char *temporary = (char*)malloc(sizeof(char) * (2*n+1));
        strcpy(temporary,temp);
        printf("temporary = %s\n",temporary);
        ret[*pCount] = temporary;
        (*pCount) += 1;
        //printf(" :组合%d\n",*pCount);
        return;
    }
    if(l > 0)
    {
        temp[k] = '(';
        printf("l = %d r = %d\n",l,r);
        printf("temp[%d] = %c\n",k,temp[k]);
        printf("temp = %s\n",temp);
        createParenthesis(n,pCount,temp,ret,l-1,r,k+1);
    }
    if(r > 0 && l < r)
    {
        temp[k] = ')';
        printf("l = %d r = %d\n",l,r);
        printf("temp[%d] = %c\n",k,temp[k]);
        printf("temp = %s\n",temp);
        createParenthesis(n,pCount,temp,ret,l,r-1,k+1);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    if(n == 0)
        return NULL;
    char *temp = (char*)malloc(sizeof(char) * (2*n+1));
    temp[2*n] = '\0';
    int *count = (int*)malloc(sizeof(int));
    *count = 0;
    generateCount(n,count,n,n,0);
    *returnSize = *count;
    printf("count = %d\n",*count);
    char **ret = (char**)malloc(sizeof(char*) * (*count));
    int *pCount = (int*)malloc(sizeof(int));
    *pCount = 0;
    createParenthesis(n,pCount,temp,ret,n,n,0);
    return ret;
}

int main() {
    printf("Hello, World!\n");
    int *rS = (int*)malloc(sizeof(int));
    *rS = 0;
    generateParenthesis(2,rS);
    return 0;
}