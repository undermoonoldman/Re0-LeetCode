/*17. Letter Combinations of a Phone Number
 * Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/


/*leetcode所提供的测试用例不含数字0,1.全部是有效的数字*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*不同数字按键对应的字母集*/
char *botton1 = "";
char *botton2 = "abc";
char *botton3 = "def";
char *botton4 = "ghi";
char *botton5 = "jkl";
char *botton6 = "mno";
char *botton7 = "pqrs";
char *botton8 = "tuv";
char *botton9 = "wxyz";
char *botton0 = " ";

int bottonSize[10];//数字按键对应字母的数目
char **botton;//二维数组，数字与字母的映射
int getStrLength(char *str)//计算字符串长度
{
    int length = 0;
    while(*str)
    {
        length++;
        str++;
    }
    return length;
}

char** initBotton(void)//初始化二维数组
{
    botton = (char **) (char**)malloc(10 * sizeof(char*));
    botton[0] = botton0;
    botton[1] = botton1;
    botton[2] = botton2;
    botton[3] = botton3;
    botton[4] = botton4;
    botton[5] = botton5;
    botton[6] = botton6;
    botton[7] = botton7;
    botton[8] = botton8;
    botton[9] = botton9;
    bottonSize[0] = 1;
    bottonSize[1] = 0;
    bottonSize[2] = 3;
    bottonSize[3] = 3;
    bottonSize[4] = 3;
    bottonSize[5] = 3;
    bottonSize[6] = 3;
    bottonSize[7] = 4;
    bottonSize[8] = 3;
    bottonSize[9] = 4;

    return botton;
}

void getCombineCount(char *digits,int *combineCount,int index)//计算给出的数字串所能组成的字母串的个数
{

    char *temp = botton[(digits[index] - '0')];//index为当前数字串的下标，digits[index]为下标所对应的数字串的数字字母，与'0'相减得到该字母所对应的整形数字值，temp指向当前下标该数字所对应的字母集数组
    if(index == getStrLength(digits))//递归到底，下标与位长相等
    {
        (*combineCount) += 1;//计数器自增
        //printf(" end of the %dst combination\n",*combineCount);
        return;
    }
    for(int i = 0 ; i < bottonSize[(digits[index] - '0')] ; i++)//尝试每个数字所对应的字母集
    {
        //printf("%c",temp[i]);
        getCombineCount(digits,combineCount,index+1);//递归调用
    }
    return;
}

void generateCombinations(char *digits,int index,int *count,char **result,char *temp)//生成所有的字母串组合(与getCombineCount函数只有一点点不同)
{
    char *p = botton[(digits[index] - '0')];
    if(index == getStrLength(digits))
    {
        char *value = (char*)malloc(sizeof(char) * getStrLength(digits));
        temp[index] = '\0';
        strcpy(value,temp);
        result[*count] = value;
        //printf("result[%d] = %s",*count,result[*count]);
        (*count) += 1;
        //printf(" end of the %dst combination\n",*count);
        return;
    }
    for(int i = 0 ; i < bottonSize[(digits[index] - '0')] ; i++)
    {
        temp[index] = p[i];
        //printf("%c\n",temp[index]);
        generateCombinations(digits,index+1,count,result,temp);
    }
    return;
}

char** letterCombinations(char* digits,int* returnSize)
{
    initBotton();//数字按键对应字母
    int *combineCount = (int*)malloc(sizeof(int));//字母组合计数(开辟空间用)
    int *count = (int*)malloc(sizeof(int));
    *count = 0;//字母组合计数(存储结果用)
    int length = getStrLength(digits);//数字串长度
    *combineCount = 0;
    getCombineCount(digits,combineCount,0);
    *returnSize = *combineCount;
    int Combine = *combineCount;
    //printf("combineCount = %d\n",*combineCount);
    //printf("returnSize = %d\n",*returnSize);

    char **result = (char**)malloc((Combine) * sizeof(char*));//开辟了拥有combineCount个一维数组的二维数组
    char *temp = (char*)malloc(sizeof(char) * length);//每个一维数组的大小
    generateCombinations(digits,0,count,result,temp);
    return result;
}

int main() {
    printf("Hello, World!\n");

    char *digits = "23";
    int *returnSize = (int*)malloc(sizeof(int));
    *returnSize = 0;
    char **ret = letterCombinations(digits,returnSize);

    for(int i = 0 ; i < *returnSize ; i++)
    {
        printf("%s\n",ret[i]);
    }

    return 0;
}