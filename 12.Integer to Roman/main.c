/**12. Integer to Roman
 * Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

 以下摘自wikipedia
 罗马数字共有7个，即Ⅰ（1）、Ⅴ（5）、Ⅹ（10）、Ⅼ（50）、Ⅽ（100）、Ⅾ（500）和Ⅿ（1000）。按照下述的规则可以表示任意正整数。需要注意的是罗马数字中没有“0”，与进位制无关。一般认为罗马数字只用来记数，而不作演算。
重复数次：一个罗马数字重复几次，就表示这个数的几倍。
右加左减：
在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
但是，左减时不可跨越一个位值。比如，99不可以用IC（ {\displaystyle 100-1} 100-1）表示，而是用XCIX（ {\displaystyle [100-10]+[10-1]} [100-10]+[10-1]）表示。（等同于阿拉伯数字每位数字分别表示。）
左减数字必须为一位，比如8写成VIII，而非IIX。
右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
加线乘千：
在罗马数字的上方加上一条横线或者加上下标的Ⅿ，表示将这个数乘以1000，即是原数的1000倍。
同理，如果上方有两条横线，即是原数的1000000（ {\displaystyle 1000^{2}} 1000^{{2}}）倍。
数码限制：
同一数码最多只能连续出现三次，如40不可表示为XXXX，而要表示为XL。
例外：由于IV是古罗马神话主神朱庇特（即IVPITER，古罗马字母里没有J和U）的首字，因此有时用IIII代替IV。
示例
罗马数字	数值	拉丁语
I	1	ūnus
Ⅱ	2	duo
Ⅲ	3	trēs
IV	4	quattuor
Ⅴ	5	quīnque
Ⅵ	6	sex
Ⅶ	7	septem
Ⅷ	8	octō
Ⅸ	9	novem
Ⅹ	10	decem
XI	11	ūndecim
XII	12	duodecim
XIII	13	tresdecim
XIV	14	quattuordecim
XV	15	quīndecim
XVI	16	sēdecim
XVII	17	septendecim
XVIII	18	octōdecim
或
duodēvīgintī
XIX	19	novendecim
或
ūndēvīgintī
XX	20	vīgintī
XXX	30	trīgintā
XL	40	quadrāgintā
L	50	quīnquāgintā
LX	60	sexāgintā
LXX	70	septuāgintā
LXXX	80	octōgintā
XC	90	nōnāgintā
XCIX	99	nōnāgintā novem
罗马数字	数值	拉丁语
C	100	centum
CI	101	centum et ūnus
CII	102	centum et duo
CXCIX	199	centum nōnāgintā novem
CC	200	ducentī
CCC	300	trecentī
CD	400	quādringentī
D	500	quingentī
DC	600	sescentī
DCC	700	septingentī
DCCC	800	octingentī
CM	900	nongentī
M	1000	mīlle
MCD	1400
MCDXXXVII	1437
MD	1500
MDCCC	1800
MCM	1900
MM	2000
MMM	3000
MMMCCCXXXIII	3333
MV	4000
V	5000
X	10000
L	50000
C	100000	deciēns
D	500000
M	1000000
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*题目说数字范围是 1~3999，一共用到个十百千四位数，下面是所有位上的字符集*/
char *single[] = {"#","I","II","III","IV","V","VI","VII","VIII","IX"};//''用于占位，方便后面直接调用下标使用
char *ten[] = {"#","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
char *hundred[] = {"#","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
char *thousand[] = {"#","M","MM","MMM"};

typedef struct node//栈辅助用
{
    char *digitStr;
    struct node *next;
}node,*pNode,*pStack;

pStack createStack(void)
{
    pStack Head = (pStack)malloc(sizeof(node));
    Head->next = NULL;
    return Head;
}

pStack push(pStack Head,char *p)
{
    pNode temp = (pNode)malloc(sizeof(node) * strlen(p));
    temp->digitStr = p;
    temp->next = Head;
    Head = temp;
    return Head;
}

char* pop(pStack Head)
{
    pNode temp = Head;
    Head = Head->next;
    return temp->digitStr;
}

char* intToRoman1(int num)//取罗马字符是从低往高，而写入时从高往低，借助下栈
{
    int digit = 0;//表示目前取哪一位
    int value;
    int index = 0;//拷贝函数下标指示
    char *ret = (char*)malloc(sizeof(char) * 13);//根据题目给出的数字范围，分配足够的空间
    char ***roman = (char***)malloc(sizeof(char**) * 4);//罗马字母字符集，个十百千四位
    pStack newStack = createStack();//初始化栈
    roman[0] = single;
    roman[1] = ten;
    roman[2] = hundred;
    roman[3] = thousand;
    while(num)
    {
        value = num % 10;
        char *p = roman[digit][value];
        if(value > 0)
        {
            newStack = push(newStack,p);//把从低到高把每位数字对应的罗马字符串压栈
        }

        digit += 1;
        num /= 10;
    }

    char *temp;
    while(newStack->next)//不断弹栈赋值，不用栈的话，产生的结果就是反的
    {
        temp = pop(newStack);
        strcpy(&ret[index],temp);
        index += strlen(temp);
        newStack = newStack->next;
    }

    return ret;
}

int getLength(int number)
{
    int length = 1;
    while(number / length >= 10)
    {
        length *= 10;
    }
    return length;
}

int getIndex(int number)
{
    int length = 1;
    int index = 0;
    while(number / length >= 10)
    {
        length *= 10;
        index++;
    }
    return index;
}

char* intToRoman2(int num)//刚才sb了，取罗马字符是从高往低，与之前相反，不用栈
{
    int digit = getIndex(num);//表示目前取哪一位
    int value;
    int length = getLength(num);
    int index = 0;//拷贝函数下标指示
    char *ret = (char*)malloc(sizeof(char) * 13);//根据题目给出的数字范围，分配足够的空间
    char ***roman = (char***)malloc(sizeof(char**) * 4);//罗马字母字符集，个十百千四位
    roman[0] = single;
    roman[1] = ten;
    roman[2] = hundred;
    roman[3] = thousand;
    while(num)
    {
        value = num / length;
        char *p = roman[digit][value];
        if(value > 0)
        {
            strcpy(&ret[index],p);
            index += strlen(p);
        }

        digit -= 1;
        num = num % length;
        length /= 10;
    }
    return ret;
}

int main()
{
    printf("Hello, World!\n");

    char *ret = intToRoman2(3333);
    printf("ret = %s\n",ret);
    return 0;
}