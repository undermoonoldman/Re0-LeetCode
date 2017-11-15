/*6. ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/

#include <stdio.h>
#include <stdlib.h>

int getStrLength(char *s)
{
    int length = 0;
    while(*s)
    {
        length++;
        s++;
    }
    return length;
}

char* convert(char* s, int numRows)//找规律的题，画图
{
    if(numRows <= 1)
        return s;
    int length = getStrLength(s);
    char *ret = (char*)malloc((length + 1) * sizeof(char));
    int circleSize = numRows * 2 - 2;//循环周期
    char *p = ret;

    for(int i = 0; i < numRows; i++)//按行输出
    {
        for(int j = i; j < length; j += circleSize)//输出一行(按下标检测一行的结束)
        {
            *p++ = s[j];

            int secondJ = (j - i) + circleSize - i;//除了首尾两行外其他行有额外数，

            if(i != 0 && i != numRows-1 && secondJ < length)//首尾两行特殊处理
                *p++ = s[secondJ];
        }
    }

    *p = '\0';
    return ret;
}

int main() {
    printf("Hello, World!\n");
    char *a = "PAYPALISHIRING";
    char *b = convert("PAYPALISHIRING",3);
    printf("after convert is %s\n",b);//PAHNAPLSIIGYIR
    return 0;
}