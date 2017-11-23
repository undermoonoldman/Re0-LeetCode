/*13. Roman to Integer
 * Given a roman numeral, convert it to an integer.

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
M	1000000*/
#include <stdio.h>
#include <string.h>
/*题目说数字范围是 1~3999，一共用到个十百千四位数，下面是所有位上的字符集*/
//char *single[] = {"#","I","II","III","IV","V","VI","VII","VIII","IX"};//''用于占位，方便后面直接调用下标使用
//char *ten[] = {"#","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
//char *hundred[] = {"#","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
//char *thousand[] = {"#","M","MM","MMM"};
//
int getPosition(char *s,char *p)//匹配串第一次出现位置，不存在返回 -1
{
    if(strstr(s,p) == NULL)
        return -1;
    else
        return (strstr(s,p) - s);
}

/*数字转罗马的方法是从高往低逐位计算，罗马转数字如果也从高往低逐位转换的话会有问题，因为罗马有前减后加的规则
 * 仔细观察罗马的字符集，发现前减的字符全部都是值为 4,9 的，把这样的数值挑出来都有4,9,40,90,400,900
 * 对应的罗马字符分别为 IV,IX;XL,XC;CD,CM。再仔细观察发现这些前减串与他们的后加串的值相差 2,20,200
 * 在一个罗马串中，一个前减字符只也仅出现一次，把所有罗马字符差成单个来累加，如果没有前减字符，得到的值正是所对应的数字值
 * 如果有前减字符，这样等于是把数算大了，大了多少，每出现一个 IV 大 2，类比*/

int romanToInt(char* s)//
{
    int sum = 0;//累加
    char *p = s;//遍历指针
    if(getPosition(s,"IV") != -1)//对不同的前减字符进行检查，因为只会出现一次
        sum -= 2;
    if(getPosition(s,"IX") != -1)
        sum -= 2;
    if(getPosition(s,"XL") != -1)
        sum -= 20;
    if(getPosition(s,"XC") != -1)
        sum -= 20;
    if(getPosition(s,"CD") != -1)
        sum -= 200;
    if(getPosition(s,"CM") != -1)
        sum -= 200;
    //提前减去前减字符造成的偏差后，全部当成后加串进行累加
    while(*p)
    {
        if(p[0] == 'M')
            sum += 1000;
        if(p[0] == 'D')
            sum += 500;
        if(p[0] == 'C')
            sum += 100;
        if(p[0] == 'L')
            sum += 50;
        if(p[0] == 'X')
            sum += 10;
        if(p[0] == 'V')
            sum += 5;
        if(p[0] == 'I')
            sum += 1;
        p++;
    }
    return sum;
}
//做了题才能痛彻了解罗马字符，之前只能认识表盘（维基百科较为准确）

int main()
{
    printf("Hello, World!\n");
    int a = romanToInt("XIV");
    printf("a = %d\n",a);
    return 0;
}
